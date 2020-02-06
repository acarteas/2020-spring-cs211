#pragma once
#include <vector>
using namespace std;
class BitVector
{
private:
	vector<long long> _bits;
	int _size = 0;
public:

	int getSize()
	{
		return _size;
	}

	void push_back(bool value)
	{

	}

	bool pop_back()
	{
		return false;
	}

	bool operator[](int index)
	{

	}
};