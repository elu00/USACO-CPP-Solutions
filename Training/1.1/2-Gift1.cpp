/*
ID: elu1
LANG: C++14
PROG: gift1
*/
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int FindIndexOf(vector<string> list, string compare)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == compare)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int n;
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	fin >> n;
	vector<string> names;
	vector<int> balance(n, 0);
	for (int i = 0; i < n; i++)
	{
		string name;
		fin >> name;
		names.push_back(name);
	}
	for (int i = 0; i < n; i++)
	{
		string giver_name;
		int giver_index;
		int total;
		int gift_number;
		fin >> giver_name >> total >> gift_number;
		giver_index = FindIndexOf(names, giver_name);
		if (!(gift_number == 0))
		{
			total = (total - (total % gift_number));
			balance[giver_index] -= total;
			for (int j = 0; j < gift_number; j++)
			{
				string reciever;
				fin >> reciever;
				int reciever_index = FindIndexOf(names, reciever);
				balance[reciever_index] += (total / gift_number);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		fout << names[i] << " " << balance[i] << "\n";
	}
	return 0;
}

