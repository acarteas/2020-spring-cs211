#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <unordered_map>
#include <functional>
#include <chrono>

using namespace std::chrono;
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
		while (data[i] <= pivot_value && i < j)
		{
			i++;
		}
		while (data[j] >= pivot_value&& i < j)
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
	quicksortHelper(data, 0, data.size() - 1);
}

void radixSort(vector<int>& data)
{
	vector<vector<int>> buckets{};
	vector<vector<int>> temp_buckets{};

	//allocate 10 boxes for each type of numeral
	buckets.resize(10);
	temp_buckets.resize(10);

	//figure out how many times we need to actually loop in our sorting
	//algorithm
	//O(N)
	int largest_magnitude = 1;
	for (int i = 0; i < data.size(); i++)
	{
		buckets[0].push_back(data[i]);
		int log_value = log10(data[i]) + 1;
		if (log_value > largest_magnitude)
		{
			largest_magnitude = log_value;
		}
	}

	for (int i = 0; i < largest_magnitude; i++)
	{
		//e.g, when i == 1...
		//tdb -> 10
		//tmb -> 100
		int to_divide_by = pow(10, i);
		int to_mod_by = to_divide_by * 10;

		//from 0s bucket to 9s bucket, place in temp_bucket
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < buckets[j].size(); k++)
			{
				//continuing from the comment example above...
				//348 -> 10s place
				//348 % 100 -> 48
				//48 / 10 -> 4
				int next_bucket_index = (buckets[j][k] % to_mod_by) / to_divide_by;
				temp_buckets[next_bucket_index].push_back(buckets[j][k]);
			}
		}

		swap(buckets, temp_buckets);
		temp_buckets.clear();
		temp_buckets.resize(10);
	}

	//buckets should be sorted, put back in original data variable
	int counter = 0;
	for (auto bucket : buckets)
	{
		for (auto number : bucket)
		{
			data[counter] = number;
			counter++;
		}
	}

}

void shellSort(vector<int>& data)
{
	vector<int> gap_sequence{ 1, 4, 10, 23, 57, 132, 301, 701, 1750, 3675, 7717, 16206, 34034, 71471 };
	for (int gap_index = gap_sequence.size() - 1; gap_index > -1; gap_index--)
	{
		int gap = gap_sequence[gap_index];

		//insertion sort from here forward
		for (int i = gap; i < data.size(); i++)
		{
			for (int j = i; j > 0 && j - gap > -1; j -= gap)
			{
				//                     j        j - 1
				//out of order if data[j] < data[j - gap]
				if (data[j] < data[j - gap])
				{
					swap(data[j], data[j - gap]);
				}
				else
				{
					break;
				}
				
			}
		}
	}
}


int main(void)
{
	unordered_map<string, function<void(vector<int>&)>> sorting_algorithms{};
	sorting_algorithms["Quick Sort"] = [](vector<int>& data) { quicksort(data); };
	sorting_algorithms["Radix Sort"] = [](vector<int>& data) { radixSort(data); };
	sorting_algorithms["Shell Sort"] = [](vector<int>& data) { shellSort(data); };

	vector<int> data{};
	int step = 5000;
	for (int i = 10000; i < 100001; i += step)
	{
		//add next increment of data
		for (int i = 0; i < step; i++)
		{
			data.push_back(rand());
		}

		cout << "Size: " << data.size() << endl;

		//benchmark for each function
		for (auto algo : sorting_algorithms)
		{
			auto to_sort = data;
			system_clock::time_point start, end;
			start = system_clock::now();
			algo.second(to_sort);
			end = system_clock::now();
			long long time_in_milliseconds = duration_cast<milliseconds>(end - start).count();
			cout << algo.first << " : " << time_in_milliseconds << endl;
		}
	}
	return 0;
}