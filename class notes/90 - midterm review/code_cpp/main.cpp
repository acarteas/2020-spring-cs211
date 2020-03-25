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
#include "PrintLog.h"
#include "StringHelpers.h"
#include "BinarySearchTree.h"

using namespace std;

template <typename T>
void preOrderTraversal(BinaryTreeNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	//us
	cout << node->value << " ";

	//left
	preOrderTraversal(node->left_child);

	//right
	preOrderTraversal(node->right_child);
}

template <typename T>
void inOrderTraversal(BinaryTreeNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	//left
	inOrderTraversal(node->left_child);

	//us
	cout << node->value << " ";

	//right
	inOrderTraversal(node->right_child);
}

template <typename T>
int getCount(BinaryTreeNode<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	//left
	int left_count = getCount(node->left_child);

	//right
	int right_count = getCount(node->right_child);

	//us
	return left_count + right_count + 1;
}

template<typename T>
void getLeafNodesHelper(BinaryTreeNode<T>* node, vector<T>& nodes)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->left_child == nullptr && node->right_child == nullptr)
	{
		nodes.push_back(node->value);
	}
	else
	{
		getLeafNodesHelper(node->left_child, nodes);
		getLeafNodesHelper(node->right_child, nodes);
	}
}

template<typename T>
vector<T> getLeafNodes(BinaryTreeNode<T>* node)
{
	vector<T> result{};
	getLeafNodesHelper(node, result);
	return result;
}

//Task: given a sequence of integers in a vector where each index
//represents a given day's rainfall (e.g. 0 -> Monday, 1 -> Tuesday...)
//calculate day with least amount of rainfall
string getDayWithLeastRain(const vector<int>& rainfall_data)
{
	unordered_map<int, string> intsAsDays{
		{ 0, "Monday" },
		{ 1, "Tuesday"},
		{ 2, "Wednesday" },
		{ 3, "Thursday"},
		{ 4, "Friday"},
		{ 5, "Saturday"},
		{ 6, "Sunday"}
	};
	unordered_map<string, int> rainfall_totals{};
	for (int i = 0; i < rainfall_data.size(); i++)
	{
		rainfall_totals[intsAsDays[i % 7]] += rainfall_data[i];
	}

	//should be "Monday"
	string day_with_most_rain = intsAsDays.begin()->second;
	int rainfall_count = INT_MAX;

	//now, run our loop
	for (auto day : rainfall_totals)
	{
		if (day.second < rainfall_count)
		{
			day_with_most_rain = day.first;
			rainfall_count = day.second;
		}
	}

	return day_with_most_rain;

	return "";
}

int main(void)
{
	vector<int> rainfall_data{};
	for (int i = 0; i < 100 * 7; i++)
	{
		rainfall_data.push_back(rand() % 10);
	}
	cout << getDayWithLeastRain(rainfall_data) << endl;
	return 0;
}