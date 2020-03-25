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

int main(void)
{
	//example using a map
	map<string, string> data{};
	data["bob"] = "smith";
	data["adam"] = "carter";
	data["sally"] = "jenkins";

	//unlike unordered_map where we cannot guarantee order
	//when itereating over the data structure, items in
	//a map come out ordered.
	//HOWEVER: this comes at a cost
	// Task       unordered_map      map
	// Insert     O(1)               O(LogN)
	
	// Retrieve   O(1)               O(LogN)
	
	// Remove     O(1)               O(LogN)
	
	// List in
	// sorted     O(NLogN)           O(N)
	for (auto kvp : data)
	{
		cout << kvp.first << " " << kvp.second << endl;
	}
	
	BinarySearchTree<int> bst{};
	for (int i = 0; i < 10; i++)
	{
		bst.addElement(rand() % 100);
	}
	return 0;
}