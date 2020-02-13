#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include "PrintLog.h"
#include "StringHelpers.h"

using namespace std;

pair<vector<PrintJob>, vector<string>> parseJobs(string jobs_file)
{
	vector<PrintJob> jobs{};
	vector<string> failed_parses{};

	ifstream printer_log_file{ jobs_file };
	while (printer_log_file.is_open() == true
		&& printer_log_file.good() == true)
	{
		string line;
		getline(printer_log_file, line);
		vector<string> pieces = split(line, ",");
		PrintJob job{};

		//always good to error check.  If not 4
		//reject line
		if (pieces.size() == 4)
		{
			try
			{
				job.date = pieces[0];
				job.pages = stoi(pieces[1]);
				job.user_id = stoi(pieces[2]);
				job.printer_id = stoi(pieces[3]);
				jobs.push_back(job);
			}
			catch (...)
			{
				failed_parses.push_back(line);
			}
		}
		else
		{
			failed_parses.push_back(line);
		}

	}
	printer_log_file.close();
	return make_pair(jobs, failed_parses);
}

void findMostPagesVector(vector<PrintJob> all_jobs)
{
	int most_pages_id = -1;
	int most_pages_count = -1;
	for (auto job : all_jobs)
	{
		int current_pages_id = job.printer_id;
		int current_pages_count = 0;
		for (auto job : all_jobs)
		{
			if (current_pages_id == job.printer_id)
			{
				current_pages_count += job.pages;
			}
			if (current_pages_count > most_pages_count)
			{
				most_pages_count = current_pages_count;
				most_pages_id = current_pages_id;
			}
		}
	}
	cout << "Printer with most pages: " << most_pages_id
		<< " (#" << most_pages_count << ")" << endl;
}

void findMostPagesHT(vector<PrintJob>& all_jobs)
{
	unordered_map<string, int> counts{};
	for (auto job : all_jobs)
	{
		counts[job.date] += job.pages;
	}
	string max_id = "";
	int max_count = -1;
	for (auto item : counts)
	{
		if (item.second > max_count)
		{
			max_count = item.second;
			max_id = item.first;
		}
	}
	cout << "printer: " << max_id << " pages: " << max_count << endl;
}

int main(void)
{
	auto data = parseJobs("printer_log.csv");
	vector<PrintJob>& all_jobs = data.first;
	//findMostPagesHT(all_jobs);

	//never assume that you know the order in which things
	//will come out of an unordered_map
	//if you need the keys to come out ordered, either ues a 
	//MAP data structure or put the keys into a vector and sort
	unordered_map<string, int> test_ht{};
	test_ht["apple"] = 1;
	test_ht["pear"] = 2;
	test_ht["grape"] = 3;
	test_ht["orange"] = 4;
	vector<string> keys{};
	for (auto kvp : test_ht)
	{
		keys.push_back(kvp.first);
	}
	sort(keys.begin(), keys.end());
	for (auto key : keys)
	{
		cout << key << " " << test_ht[key] << endl;
	}
	return 0;
}