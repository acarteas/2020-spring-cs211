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

unordered_map<string,GraphNode*> buildMST(unordered_map<string,GraphNode*>& graph, string start_key)
{
	/*
		1. Pick some arbitrary starting vertex.  From the selected vertex,
			we push all outgoing edges into a PQ (very similar to Dijkstra's algorithm)
	2. While the graph is not fully connected:
		a. Pop off top edge.  If vertex is not seen before, accept vertex.
			Push all new edges from this accepted vertex to the PQ
	*/
	unordered_map<string, GraphNode*> result;
	GraphNode* start = graph[start_key];
	result[start_key] = new GraphNode{};
	result[start_key]->key = start_key;

	unordered_map<string, int> connected_vertices{};

	//                   EW,       SOURCE, SINK
	priority_queue <pair<int, pair<string, string>>, vector<pair<int, pair<string, string>>>, greater<pair<int, pair<string, string>>>> pq{};
	for (auto edge : start->adjacent_vertices)
	{
		//edge is a KVP with .first being a string and .second being a pair of <GraphNode*,int>
		auto edge_pair = make_pair(start->key, edge.first);
		auto pq_pair = make_pair(edge.second.second, edge_pair);
		pq.push(pq_pair);
	}
	while (pq.empty() == false)
	{
		auto top_pair = pq.top();
		pq.pop();

		if (connected_vertices[top_pair.second.second] == 0)
		{
			//prevent future action on this node
			connected_vertices[top_pair.second.second]++;

			
			GraphNode* current = graph[top_pair.second.second];
			GraphNode* new_node = new GraphNode{};
			string key = current->key;
			new_node->key = key;
			new_node->adjacent_vertices[top_pair.second.first] = make_pair(graph[top_pair.second.first], top_pair.first);

			//add to result graph
			result[key] = new_node;

			//push on outgoing edges
			for (auto edge : current->adjacent_vertices)
			{
				//edge is a KVP with .first being a string and .second being a pair of <GraphNode*,int>
				auto edge_pair = make_pair(current->key, edge.first);
				auto pq_pair = make_pair(edge.second.second, edge_pair);
				pq.push(pq_pair);
			}
		}
	}
	return result;
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
	auto result = buildMST(graph, "A");
	return 0;
}