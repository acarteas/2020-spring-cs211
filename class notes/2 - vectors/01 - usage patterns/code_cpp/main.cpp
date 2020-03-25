#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
int main(void)
{
	vector<string> data = split("__aa__b__ccc__a____ab___", "__");
	string converted = join(data, "__");
	//Vector READ pattern
	//example of a sequential file read behavior using a vector
	vector<string> names{};
	ifstream file{ "first_names.txt" };
	while (file.is_open() && file.good())
	{
		//pattern: adding things sequentially to vector based on 
		//when they occur in the file
		string name;
		file >> name;
		names.push_back(name);
	}

	//Vector PROCESS pattern
	//"classic" process pattern
	for (int i = 0; i < names.size(); i++)
	{
		//cout << names[i];
	}

	//"modern" process pattern (also very common in other languages)
	for (auto name : names)
	{
		//cout << name;
	}

	//Vector MODIFY pattern
	//"classic" modify
	for (int i = 0; i < names.size(); i++)
	{
		//Modify logic goes here
		names[i][0] = ' ';
	}

	//"modern" FOR loop requires a slight change in setup
	for (auto& name : names)
	{
		//No & above means changes WILL NOT stick
		name[0] = '_';
	}

	//LOOK-AHEAD processing on vectors
	//requires "classic" FOR loop
	vector<int> fib_nums{};
	fib_nums.push_back(1);
	fib_nums.push_back(1);
	for (int i = 2; i < 100; i++)
	{
		//NOT possible to do "look back" with modern loop
		fib_nums.push_back(fib_nums[i - 1] + fib_nums[i - 2]);
	}

	return 0;
}