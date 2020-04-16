using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tile
{
    public string Name { get; set; }
    public int Weight { get; set; }
    public Vector3Int Position { get; set; }
    public Tile()
    {

    }

    public Tile(Tile other)
    {
        Name = other.Name;
        Weight = other.Weight;
        Position = new Vector3Int(other.Position.x, other.Position.y, other.Position.z);
    }
}
