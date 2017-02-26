/*
ID: elu1
LANG: C++14
PROG: milk2
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int most_active = 0;
	int most_idle = 0;
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	vector<vector<int>> all;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		int begin;
		int end;
		fin >> begin >> end;
		all.push_back({ begin,end });
	}
	sort(all.begin(), all.end());
	for (int i = 1; i <all.size(); i++)
	{
		//remove overlap
		if (all[i][0] <= all[i - 1][1]) {
			all[i - 1][1] = max(all[i][1], all[i - 1][1]);
			all.erase(all.begin() + (i--));
		}
	}
	for (int i = 0; i < all.size(); i++)
	{
		most_active = max(all[i][1] - all[i][0], most_active);
		if (i == all.size() - 1) break;
		most_idle = max(all[i + 1][0] - all[i][1], most_idle);
	}
	fout << most_active << " " << most_idle << "\n";
	return(0);
}
