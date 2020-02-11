#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> mergeSorted(vector<int>& left, vector<int>& right)
{
	vector<int>result{};
	return result;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> erase_range(vector<int>& input, int start, int stop);
vector<int> erase_single(vector<int>& start, int position)
{
    return erase_range(start, position, position + 2);
}

vector<int> erase_range(vector<int>& input, int start, int stop)
{
    int end = stop;
    for (int i = start - 1; i < input.size() && end < input.size(); i++)
    {
        input[i] = input[end];
        end++;
    }
    while (end > stop)
    {
        input.pop_back();
        end--;
    }
    return input;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> input_values{};
    int size = 0;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        input_values.push_back(temp);
    }
    int first_query;
    cin >> first_query;
    int min_range;
    int max_range;
    cin >> min_range;
    cin >> max_range;
    vector<int> result = erase_single(input_values, first_query);
    result = erase_range(result, min_range, max_range);
    cout << result.size() << endl;
    for (auto value : result)
    {
        cout << value << " ";
    }
    return 0;
}