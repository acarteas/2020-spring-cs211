#pragma once

//AC: this is a lazy-mode implementation w/o getters and
//setters
template <typename T>
class BinaryTreeNode
{
public:
	T value;
	BinaryTreeNode<T>* left_child = nullptr;
	BinaryTreeNode<T>* right_child = nullptr;

	BinaryTreeNode(const T& value)
		: value(value) {}

	BinaryTreeNode() {}


	virtual ~BinaryTreeNode() {}
};