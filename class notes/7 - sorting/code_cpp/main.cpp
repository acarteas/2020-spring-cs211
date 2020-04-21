#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>

using namespace std;

//easy pivot selection that avoids worst case n^2 runtime
int getPivot(vector<int>& data, int start_bound, int end_bound)
{
	//assume choice is our starting index, and look for alternate proof
	int pivot_index = start_bound;
	int midpoint = ((end_bound - start_bound) / 2) + start_bound;
	int start_value = data[start_bound];
	int mid_value = data[midpoint];
	int end_value = data[end_bound];

	//is the middle the best pivot?
	if (mid_value > start_value&& mid_value < end_value)
	{
		pivot_index = midpoint;
	}
	else if (mid_value < start_value && mid_value > end_value)
	{
		pivot_index = midpoint;
	}

	//is end value the best pivot?
	if (end_value > start_value&& end_value < mid_value)
	{
		pivot_index = end_bound;
	}
	else if (end_value < start_value && end_value > mid_value)
	{
		pivot_index = end_bound;
	}
	return pivot_index;
}

void quicksortHelper(vector<int>& data, int start_index, int end_index)
{
	//base case #1: array of size 1
	if (end_index <= start_index)
	{
		return;
	}

	//base case #2: array of size 2
	if (end_index - start_index == 1)
	{
		if (data[end_index] < data[start_index])
		{
			swap(data[end_index], data[start_index]);
		}
	}

	//because we're using a best of three pivot selection, we must ensure that 
	//our array is at least of size 3
	int pivot_index = getPivot(data, start_index, end_index);

	//if we move pivot out of the way (just put it at the end), our algorithm for swapping
	//is as follows:
	//i = start_index
	//j = end_index - 1
	//while data[i] < pivot_value AND i < j:
	//	i++
	//while data[j] > pivot_value AND i < j:
	//	j--
	//if i != j:
	//	swap data[i], data[j]
	int pivot_value = data[pivot_index];
	swap(data[pivot_index], data[end_index]);
	int i = start_index;
	int j = end_index - 1;
	while (i < j)
	{
		while (data[i] < pivot_value && i < j)
		{
			i++;
		}
		while (data[j] > pivot_value&& i < j)
		{
			j--;
		}
		if (i < j)
		{
			swap(data[i], data[j]);
		}
	}

	//finally swap pivot with data[i]
	swap(data[i], data[end_index]);

	//recursively repeat
	quicksortHelper(data, start_index, i - 1);
	quicksortHelper(data, i + 1, end_index);
}

void quicksort(vector<int>& data)
{
	quicksortHelper(data, 0, data.size() - 1)
		;
}


int main(void)
{

	return 0;
}