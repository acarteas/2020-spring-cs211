#pragma once
#include "BinaryTreeNode.h"

template <typename T>
class BinarySearchTree
{
protected:
	BinaryTreeNode<T>* _root = nullptr;

	BinaryTreeNode<T>* findLargest(BinaryTreeNode<T>* start)
	{
		while (start != nullptr && start->right_child != nullptr)
		{
			start = start->right_child;
		}
		return start;
	}

	virtual BinaryTreeNode<T>* removeElementHelper(BinaryTreeNode<T>* node, const T& value)
	{
		//case #1: value does not exist in tree
		if (node == nullptr)
		{
			return nullptr;
		}
		if (value < node->value)
		{
			BinaryTreeNode<T>* result = removeElementHelper(node->left_child, value);
			node->left_child = result;
		}
		else if (value > node->value)
		{
			BinaryTreeNode<T>* result = removeElementHelper(node->right_child, value);
			node->right_child = result;
		}
		else
		{
			if (node->left_child == nullptr &&
				node->right_child == nullptr)
			{
				delete node;
				return nullptr;
			}
			else if (node->left_child == nullptr)
			{
				BinaryTreeNode<T>* result = node->right_child;
				delete node;
				return result;
			}
			else if (node->right_child == nullptr)
			{
				BinaryTreeNode<T>* result = node->left_child;
				delete node;
				return result;
			}
			else
			{
				//We only get here if BOTH children ARE NOT NULL
				BinaryTreeNode<T>* largest = findLargest(node->left_child);
				node->value = largest->value;
				BinaryTreeNode<T>* result = removeElementHelper(node->left_child, largest->value);
				node->left_child = result;
			}
			return node;
		}
	}


	virtual BinaryTreeNode<T>* addElementRec(BinaryTreeNode<T>* node, const T& value)
	{
		//base case
		if (node == nullptr)
		{
			return new BinaryTreeNode<T>{ value };
		}

		//where does the value belong?
		if (value >= node->value)
		{
			BinaryTreeNode<T>* result = addElementRec(node->right_child, value);
			node->right_child = result;
		}
		else
		{
			BinaryTreeNode<T>* result = addElementRec(node->left_child, value);
			node->left_child = result;
		}
		return node;
	}

public:

	void addElement(const T& value)
	{
		_root = addElementRec(_root, value);
	}
	void removeElement(const T& value)
	{
		_root = removeElementHelper(_root, value);
	}
};