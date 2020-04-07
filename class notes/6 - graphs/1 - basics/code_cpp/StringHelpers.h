#pragma once
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<string> split(string input, string sep)
{
	vector<string> result{};
	string current = "";  //vector in hiding

	//we're using look-ahead, so classic loop is required
	for (int i = 0; i < input.size(); i++)
	{
		//another loop to check for presence of separator
		bool is_sep = true;
		int sep_counter = 1;
		for (int j = 0; j < sep.size() && is_sep == true; j++)
		{
			if (input[i + j] != sep[j] || i + j >= input.size())
			{
				is_sep = false;
			}
			else
			{
				sep_counter++;
			}
		}

		//non-separators get added to current word
		if (is_sep == false)
		{
			for (int j = 0; j < sep_counter; j++)
			{
				current.push_back(input[i + j]);
			}
			i += sep_counter - 1;
		}
		else
		{
			//skip remaining separator chars
			i += sep.length() - 1;
			result.push_back(current);
			current = "";
		}
	}

	//add on last of current string
	result.push_back(current);
	return result;
}
string join(vector<string>& data, string sep)
{
	ostringstream result{};
	for (int i = 0; i < data.size() - 1; i++)
	{
		result << data[i];
		result << sep;
	}
	result << data[data.size() - 1];
	return result.str();
}
