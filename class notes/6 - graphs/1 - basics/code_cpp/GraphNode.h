#pragma once
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class GraphNode
{
public:
	string key;
	string value;
	unordered_map<string, pair<GraphNode*, int>> adjacent_vertices;
};