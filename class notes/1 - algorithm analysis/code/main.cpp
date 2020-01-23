#include <iostream>
#include <string>
#include <vector>

using namespace std;

//example of a linear algorithm
int search(int value, vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
}

//O(1 + N + N^3)
//reduces to O(N^3)
//O(N^3 + N^3) = O(2N^3) = O(N^3)

//Log behavior might be represented as
//O(LogN)
//O(NLogN)
vector<vector<int>> multiply(vector<vector<int>> a,
	vector<vector<int>> b
)
{
	vector<vector<int>> result{};

	//hack: assume both are square
	if (a.size() != b.size() && a[0].size() != b[0].size())
	{
		return result;
	}

	//make result same size as a
	result.resize(a.size());
	for (int i = 0; i < result.size(); i++)
	{
		result[i].resize(a[0].size());
	}

	//finally do the multiply
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			for (int k = 0; k < b.size(); k++)
			{
				result[i][j] += a[i][j] * b[k][j];
			}
		}
	}
}

int add(int a, int b)
{
	if (b > 0)
	{
		return add(a, b - 1);
	}
	return a;
}

int main(void)
{
	return 0;
}