using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TileFactory
{
    private Dictionary<string, Tile> _tiles = new Dictionary<string, Tile>();
    private static TileFactory _instance = null;

    private TileFactory()
    {
        _tiles.Add("OutdoorsGround_0", new Tile() { 
            Name = "Grass",
            Weight = 5
        });
        _tiles.Add("OutdoorsGround_6", new Tile()
        {
            Name = "Road",
            Weight = 2
        });
        _tiles.Add("Generic", new Tile()
        {
            Name = "Unknown",
            Weight = 10
        });
    }

    public static TileFactory GetInstance()
    {
        if(_instance == null)
        {
            _instance = new TileFactory();
        }
        return _instance;
    }

    public Tile GetTile(string tileName)
    {
        if (_tiles.ContainsKey(tileName))
        {
            return _tiles[tileName];
        }
        else
        {
            return _tiles["Generic"];
        }
    }
}
