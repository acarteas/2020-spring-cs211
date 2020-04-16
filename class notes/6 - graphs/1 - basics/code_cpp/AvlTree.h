#pragma once
#include "BinarySearchTree.h"
#include "AvlTreeNode.h"

template <typename T>
class AvlTree : public BinarySearchTree<T>
{
protected:
	BinaryTreeNode<T>* setHeight(BinaryTreeNode<T>* node)
	{
		int left_height = -1;
		int right_height = -1;
		AvlTreeNode<T>* left = dynamic_cast<AvlTreeNode<T>*>(node->left_child);
		AvlTreeNode<T>* right = dynamic_cast<AvlTreeNode<T>*>(node->right_child);
		if (left != nullptr)
		{
			left_height = left->height;
		}
		if (right != nullptr)
		{
			right_height = right->height;
		}
		int height = (left_height < right_height) ? right_height : left_height;
		height++;
		AvlTreeNode<T>* avl_node = dynamic_cast<AvlTreeNode<T>*>(node);
		if (avl_node != nullptr)
		{
			avl_node->height = height;
		}
		return node;
	}

	BinaryTreeNode<T>* rotateLeft(BinaryTreeNode<T>* node)
	{
		BinaryTreeNode<T>* new_root = node->right_child;
		node->right_child = new_root->left_child;
		new_root->left_child = node;
		return new_root;
	}

	BinaryTreeNode<T>* rotateRight(BinaryTreeNode<T>* node)
	{
		BinaryTreeNode<T>* new_root = node->left_child;
		node->left_child = new_root->right_child;
		new_root->right_child = node;
		return new_root;
	}

	virtual BinaryTreeNode<T>* addElementRec(BinaryTreeNode<T>* node, const T& value)
	{
		if (node == nullptr)
		{
			return setHeight(new AvlTreeNode<T>{ value });
		}
		BinaryTreeNode<T>* result = BinarySearchTree<T>::addElementRec(node, value);
		result = setHeight(result);
		return result;
	}

};