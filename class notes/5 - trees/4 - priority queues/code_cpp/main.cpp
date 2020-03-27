#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	for (int i = 0; i < 10; i++)
	{
		max_pq.push(rand());
		min_pq.push(rand());
	}

	while (max_pq.empty() == false)
	{
		cout << max_pq.top() << endl;
		max_pq.pop();
	}

	while (min_pq.empty() == false)
	{
		cout << min_pq.top() << endl;
		min_pq.pop();
	}



	return 0;
}