using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TilePath : IComparable<TilePath>, IEnumerable<Tile>
{
    private List<Tile> _tiles = new List<Tile>();
    public int Weight { get; private set; }

    public TilePath()
    {

    }

    public TilePath(TilePath toCopy)
    {
        Weight = toCopy.Weight;
        foreach (var item in toCopy._tiles)
        {
            _tiles.Add(item);
        }
    }

    public void AddTileToPath(Tile tile)
    {
        _tiles.Add(new Tile(tile));
        Weight += tile.Weight;
    }

    public Tile GetMostRecentTile()
    {
        return _tiles[_tiles.Count - 1];
    }

    public int CompareTo(object obj)
    {
        return CompareTo(obj as TilePath);
    }

    public int CompareTo(TilePath other)
    {
        if (other == null)
        {
            throw new Exception("Incompatable compare types.");
        }
        return Weight.CompareTo(other.Weight);
    }

    public List<Tile> GetPath()
    {
        return _tiles;
    }

    public IEnumerator<Tile> GetEnumerator()
    {
        return ((IEnumerable<Tile>)_tiles).GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return ((IEnumerable<Tile>)_tiles).GetEnumerator();
    }
}

