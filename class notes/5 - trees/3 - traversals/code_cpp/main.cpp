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


int main(void)
{
	BinarySearchTree<int> bst{};

	for (int i = 0; i < 10; i++)
	{
		bst.addElementRec(rand() % 100);
	}
	//bst.removeElement(41);
	preOrderTraversal(bst.getRoot());
	cout << endl;
	inOrderTraversal(bst.getRoot());
	cout << endl;
	cout << getCount(bst.getRoot()) << endl;
	for (auto value : getLeafNodes(bst.getRoot()))
	{
		cout << value << " ";
	}
	cout << endl;
	return 0;
}