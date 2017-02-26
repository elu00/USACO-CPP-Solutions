// Problem_1.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout("crossroad.out");
	ifstream fin("crossroad.in");
	int n;
	int crossings = 0;
	fin >> n;
	vector<int> current_state = { 0,2,2,2,2,2,2,2,2,2,2 };
	for (int i = 1; i <= n; i++)
	{
		int id;
		int status;
		fin >> id >> status;
		if (!(current_state.at(id) == 2 || current_state.at(id) == status))
		{
			crossings++;
		}
		current_state.at(id) = status;
	}
	fout << crossings;
	return 0;
}