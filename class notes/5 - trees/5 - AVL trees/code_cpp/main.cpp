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
#include "AvlTree.h"

using namespace std;

int main(void)
{
	AvlTree<int>* tree = new AvlTree<int>{};

	for (int i = 0; i < 10; i++)
	{
		tree->addElement(rand() % 100);
	}
	tree->removeElement(41);
	return 0;
}