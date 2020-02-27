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
#include "PrintLog.h"
#include "StringHelpers.h"

using namespace std;

string reverse(string text)
{
	stack<char> char_stack{};
	for (auto ch : text)
	{
		char_stack.push(ch);
	}
	for (int i = 0; i < text.length(); i++)
	{
		char temp = char_stack.top();
		char_stack.pop();
		text[i] = temp;
	}
	return text;
}

string reverseWithQueue(string text)
{
	queue<char> char_queue{};
	while(text.length() > 0)
	{
		char_queue.push(*(text.end() - 1));
		text.pop_back();
	}
	while (char_queue.empty() == false)
	{
		char ch = char_queue.front();
		char_queue.pop();
		text.push_back(ch);
	}
	return text;
}

int main(void)
{
	cout << reverseWithQueue("this is a test") << endl;
	return 0;
}