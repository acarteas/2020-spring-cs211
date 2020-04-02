using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;

public class SelectionStateMachine
{
    private static SelectionStateMachine _instance;

    private SelectionState _current_state;
    private SelectionState _noUserSelectedTileState;
    private SelectionState _userSelectedTileState;

    public static SelectionStateMachine GetInstance(Tilemap terrainMap, Tilemap uiMap, TileBase HighlightTile, TileBase SelectedTile)
    {
        if (_instance == null)
        {
            _instance = new SelectionStateMachine(terrainMap, uiMap, HighlightTile, SelectedTile);
        }
        return _instance;
    }

    private SelectionStateMachine(Tilemap terrainMap, Tilemap mouseTileMap, TileBase highlight, TileBase selected)
    {
        _noUserSelectedTileState = new NoUserSelectionState(this, mouseTileMap)
        {
            HighlightTile = highlight,
            SelectedTile = selected
        };
        _userSelectedTileState = new UserSelectionState(this, mouseTileMap, terrainMap)
        {
            HighlightTile = highlight,
            SelectedTile = selected
        };
        _current_state = _noUserSelectedTileState;

    }

    public void SetStateToUserSelected(Vector3Int selectedPosition)
    {
        _current_state = _userSelectedTileState;
        (_current_state as UserSelectionState).SelectedTilePosition = selectedPosition;
    }

    public void SetStateToNoUserSelectedTile()
    {
        _current_state = _noUserSelectedTileState;
    }

    public void ProcessMouseMovement(Vector3Int position)
    {
        _current_state.HandleMouseMovement(position);
    }

    public void ProcessMouseLeftClick(Vector3Int position)
    {
        _current_state.HandleMouseClick(position);
    }
}

public abstract class SelectionState
{
    protected SelectionStateMachine StateMachine { get; set; }
    protected Tilemap MouseTileMap { get; set; }
    protected TileBase NullTile { get; set; }

    public SelectionState(SelectionStateMachine machine, Tilemap mosueMap)
    {
        StateMachine = machine;
        MouseTileMap = mosueMap;
    }

    public abstract void HandleMouseMovement(Vector3Int position);
    public abstract void HandleMouseClick(Vector3Int position);
}

public class NoUserSelectionState : SelectionState
{
    public TileBase HighlightTile { get; set; }
    public TileBase SelectedTile { get; set; }
    protected Vector3Int LastHoverPosition { get; set; }
    public NoUserSelectionState(SelectionStateMachine machine, Tilemap map) : base(machine, map) { }

    protected virtual void ClearTile(Vector3Int position)
    {
        MouseTileMap.SetTile(position, NullTile);
    }

    public override void HandleMouseClick(Vector3Int position)
    {
        Debug.Log(string.Format("Click on {0},{1}", position.x, position.y));
        ClearTile(LastHoverPosition);
        MouseTileMap.SetTile(position, SelectedTile);
        StateMachine.SetStateToUserSelected(position);
    }


    public override void HandleMouseMovement(Vector3Int position)
    {
        ClearTile(LastHoverPosition);
        MouseTileMap.SetTile(position, HighlightTile);
        LastHoverPosition = position;
    }
}

public class UserSelectionState : NoUserSelectionState
{
    public Vector3Int SelectedTilePosition { get; set; }
    public Tilemap TerrainMap { get; set; }
    private List<Tile> _lastPath = new List<Tile>();
    public UserSelectionState(SelectionStateMachine machine, Tilemap map, Tilemap terrain) : base(machine, map)
    {
        TerrainMap = terrain;
        ResetSelectedTile();
    }

    private void ResetSelectedTile()
    {
        //you can't null a Vector3Int, so just set it to an improbable value
        SelectedTilePosition = new Vector3Int(int.MinValue, int.MinValue, int.MinValue);
    }

    public override void HandleMouseClick(Vector3Int position)
    {
        //if clicks on same spot as current selected tile, de-select and change
        //back to no user selection state
        ClearTile(SelectedTilePosition);
        ClearLastPath();
        if (SelectedTilePosition == position)
        {
            ResetSelectedTile();
            StateMachine.SetStateToNoUserSelectedTile();
        }
        else
        {
            //otherwise, readjust focused object
            MouseTileMap.SetTile(position, SelectedTile);
            SelectedTilePosition = position;
        }
    }

    private void ClearLastPath()
    {
        for (int i = 1; i < _lastPath.Count; i++)
        {
            ClearTile(_lastPath[i].Position);
        }
    }

    public override void HandleMouseMovement(Vector3Int position)
    {
        base.HandleMouseMovement(position);
        if(SelectedTilePosition != position)
        {
            var path = PathFinder.DiscoverPath(TerrainMap, SelectedTilePosition, position);
            var tiles = path.GetPath();

            //clear out old path
            ClearLastPath();

            //draw in new path
            for(int i = 1; i < tiles.Count; i++)
            {
                MouseTileMap.SetTile(tiles[i].Position, HighlightTile);
            }

            //remember path for next time
            _lastPath = tiles;
        }
        MouseTileMap.SetTile(SelectedTilePosition, SelectedTile);
    }
}

public class TileSelectionManager : MonoBehaviour
{
    public Tilemap MouseTileMap;
    public Tilemap TerrainTileMap;
    public TileBase HighlightTile;
    public TileBase SelectedTile;
    private SelectionStateMachine _selectionStateMachine;

    // Start is called before the first frame update
    void Start()
    {
        _selectionStateMachine = SelectionStateMachine.GetInstance(TerrainTileMap, MouseTileMap, HighlightTile, SelectedTile);
    }

    private bool HasMouseMoved()
    {
        if (Input.GetAxis(ProgramConstants.MouseX) < 0)
        {
            return true;
        }
        else if (Input.GetAxis(ProgramConstants.MouseX) > 0)
        {
            return true;
        }
        else if (Input.GetAxis(ProgramConstants.MouseY) > 0)
        {
            return true;
        }
        else if (Input.GetAxis(ProgramConstants.MouseY) < 0)
        {
            return true;
        }
        return false;
    }

    // Update is called once per frame
    void Update()
    {
        //for some reason, Unity NULLs out my private variables some time 
        //TODO: investigate why
        if (_selectionStateMachine == null)
        {
            _selectionStateMachine = SelectionStateMachine.GetInstance(TerrainTileMap, MouseTileMap, HighlightTile, SelectedTile);
        }

        if (HasMouseMoved() == true)
        {
            Vector2 mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            Vector3Int mapPosition = TerrainTileMap.WorldToCell(mousePosition);

            if (TerrainTileMap.HasTile(mapPosition))
            {
                _selectionStateMachine.ProcessMouseMovement(mapPosition);
            }
        }
        if (Input.GetMouseButtonDown(ProgramConstants.MouseLeftClick) == true)
        {
            Vector2 mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            Vector3Int mapPosition = TerrainTileMap.WorldToCell(mousePosition);

            if (TerrainTileMap.HasTile(mapPosition))
            {
                _selectionStateMachine.ProcessMouseLeftClick(mapPosition);
            }
        }
    }
}