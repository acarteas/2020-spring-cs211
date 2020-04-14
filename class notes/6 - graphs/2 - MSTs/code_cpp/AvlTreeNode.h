#pragma once
#include "BinaryTreeNode.h"

template <typename T>
class AvlTreeNode : public BinaryTreeNode<T>
{
public:
	int height = -1;

	AvlTreeNode(const T& value) : BinaryTreeNode<T>(value) {}
};