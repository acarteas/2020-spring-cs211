using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;

public class PathFinder
{
    public static TilePath DiscoverPath(Tilemap map, Vector3Int start, Vector3Int end)
    {
        //you will return this path to the user.  It should be the shortest path between
        //the start and end vertices 
        TilePath discoveredPath = new TilePath();

        //TileFactory is how you get information on tiles that exist at a particular vector's
        //coordinates
        TileFactory tileFactory = TileFactory.GetInstance();

        //This is the priority queue of paths that you will use in your implementation of
        //Dijkstra's algorithm
        PriortyQueue<TilePath> pathQueue = new PriortyQueue<TilePath>();

        //You can slightly speed up your algorithm by remembering previously visited tiles.
        //This isn't strictly necessary.
        Dictionary<Vector3Int, int> discoveredTiles = new Dictionary<Vector3Int, int>();

        //quick sanity check
        if(map == null || start == null || end == null)
        {
            return discoveredPath;
        }

        //This is how you get tile information for a particular map location
        //This gets the Unity tile, which contains a coordinate (.Position)
        var startingMapLocation = map.GetTile(start);

        //And this converts the Unity tile into an object model that tracks the
        //cost to visit the tile.
        var startingTile = tileFactory.GetTile(startingMapLocation.name);
        startingTile.Position = start;

        //Any discovered path must start at the origin!
        discoveredPath.AddTileToPath(startingTile);

        //This adds the starting tile to the PQ and we start off from there...
        pathQueue.Enqueue(discoveredPath);
        bool found = false;

        var endingMapLocation = map.GetTile(end);


        var endingTile = tileFactory.GetTile(endingMapLocation.name);
        endingTile.Position = end;

        while (found == false && pathQueue.IsEmpty() == false)
        {

            /* 1.Add starting location to a priority queue
             2.While the priority queue is not empty and while you have not reached your final tile:
              *Pop the top item off of the priority queue
             *If the item contains the final tile in the path, you are done.
         *If not, for each of the tile's neighbors (there should be 4 since we're using square tiles)
         *Create a new path with the additional tile.  
         *If that path contains the final tile, you're done.
        * If not, add that path back into the Priority Queue.
         3.Return the path discovered in Step #2 back to the caller. */
            //TODO: Implement Dijkstra's algorithm!


            //*Pop the top item off of the priority queue
            TilePath item = pathQueue.Dequeue();
            Tile myTile = item.GetMostRecentTile();

            //*If the item contains the final tile in the path, you are done.
            if(myTile.Position.Equals(end))
            {
               
                found = true;
                break;

            }

           // *If not, for each of the tile's neighbors (there should be 4 since we're using square tiles)
          //*Create a new path with the additional tile. 
          else
            {
                List<Tile> neighbors = getNeighbors(map, myTile);
                for (int i = 0; i < neighbors.Count; i++)
                {
                    TilePath neighbor = new TilePath();
                    neighbor.AddTileToPath(neighbors[i]);

                    //Write function later
                    // *If that path contains the final tile, you're done.
                   if(containsEnd(neighbor, end))

                    {
                        found = true;
                        break;
                    }

                }
            }



            //This line ensures that we don't get an infinite loop in Unity.
            //You will need to remove it in order for your pathfinding algorithm to work.
            found = true;
        }
        return discoveredPath;
    }
}
