// mememememememe.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
	ofstream fout("cowqueue.out");
	ifstream fin("cowqueue.in");
	int n;
	int time = 0;
	vector<vector<int>> all;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		int arrival;
		int duration;
		fin >> arrival >> duration;
		vector<int> newcow = { arrival, duration };
		all.push_back(newcow);
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < n; i++)
	{
		int arrival = all[i][0];
		int duration = all[i][1];
		(time >= arrival) ? time += duration : time = arrival + duration;
	}
	fout << time;
	return 0;
}

