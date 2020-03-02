#pragma once
#include "BinaryTreeNode.h"

template <typename T>
class BinarySearchTree
{
private:
	BinaryTreeNode<T>* _root = nullptr;

public:
	void addElement(const T& value)
	{
		BinaryTreeNode<T>* current = _root;
		while (current != nullptr)
		{
			BinaryTreeNode<T>* temp = nullptr;
			if (value >= current->value)
			{
				//right child
				temp = current->right_child;
			}
			else
			{
				//left child
				temp = current->left_child;
			}

			if (temp != nullptr)
			{
				current = temp; 
			}
			else
			{
				break;
			}
		}

		//now current will be the parent of the new child
		BinaryTreeNode<T>* node = new BinaryTreeNode<T>{ value };
		if (current == nullptr)
		{
			_root = node;
		}
		else if (value >= current->value)
		{
			current->right_child = node;
		}
		else
		{
			current->left_child = node;
		}
	}
};