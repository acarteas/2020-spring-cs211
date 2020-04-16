#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <map> //a map is a "red-black" binary tree
#include "GraphNode.h"

using namespace std;

bool isConnectDfsHelper(GraphNode* node, string destination, unordered_map<string, int>& visited)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->key == destination)
	{
		return true;
	}
	visited[node->key]++;
	for (auto kvp : node->adjacent_vertices)
	{
		if (visited[kvp.first] > 0)
		{
			continue;
		}
		bool result = isConnectDfsHelper(kvp.second.first, destination, visited);
		if (result == true)
		{
			return true;
		}
	}
	return false;
}

bool isConnectedDfs(GraphNode* start, string destination_key)
{
	unordered_map<string, int> visited{};
	return isConnectDfsHelper(start, destination_key, visited);
}

bool isConnectedBfs(GraphNode* start, string destination_key)
{
	queue<GraphNode*> to_visit{};
	unordered_map<string, int> visited{};
	to_visit.push(start);
	while (to_visit.empty() == false)
	{
		GraphNode* next = to_visit.front();
		to_visit.pop();

		//mark as visited
		visited[next->key]++;

		for (auto kvp : next->adjacent_vertices)
		{
			if (visited[kvp.first] > 0)
			{
				//continue;
			}
			if (kvp.first == destination_key)
			{
				return true;
			}
			to_visit.push(kvp.second.first);
		}
	}
	return false;
}

int main(void)
{
	unordered_map<string, GraphNode*> graph{};
	graph["A"] = new GraphNode{};
	graph["A"]->key = "A";
	graph["B"] = new GraphNode{};
	graph["B"]->key = "B";
	graph["C"] = new GraphNode{};
	graph["C"]->key = "C";
	graph["D"] = new GraphNode{};
	graph["D"]->key = "D";
	graph["E"] = new GraphNode{};
	graph["E"]->key = "E";

	//connect nodes
	graph["A"]->adjacent_vertices["A"] = make_pair(graph["A"], 0);
	graph["A"]->adjacent_vertices["B"] = make_pair(graph["B"], 2);
	graph["A"]->adjacent_vertices["D"] = make_pair(graph["D"], 3);

	graph["B"]->adjacent_vertices["A"] = make_pair(graph["A"], 2);
	graph["B"]->adjacent_vertices["B"] = make_pair(graph["B"], 0);
	graph["B"]->adjacent_vertices["C"] = make_pair(graph["C"], 2);
	graph["B"]->adjacent_vertices["D"] = make_pair(graph["D"], 3);
	graph["B"]->adjacent_vertices["E"] = make_pair(graph["E"], 4);

	graph["C"]->adjacent_vertices["B"] = make_pair(graph["B"], 2);
	graph["C"]->adjacent_vertices["C"] = make_pair(graph["C"], 0);

	graph["D"]->adjacent_vertices["A"] = make_pair(graph["A"], 3);
	graph["D"]->adjacent_vertices["B"] = make_pair(graph["B"], 3);
	graph["D"]->adjacent_vertices["D"] = make_pair(graph["D"], 0);

	graph["E"]->adjacent_vertices["B"] = make_pair(graph["B"], 4);
	graph["E"]->adjacent_vertices["E"] = make_pair(graph["E"], 0);

	cout << boolalpha;
	cout << isConnectedDfs(graph["A"], "E") << endl;

	return 0;
}