/*
ID: elu1
LANG: C++14
PROG: transform
*/
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
int spooky(vector<vector<char>> _init, vector<vector<char>> _final, int n, int a)
{
	if (a = 4)
	{
		return 0;
	}
	vector<vector<char>> _temp;
	bool good = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			_temp[j][abs(i - n)] = _init[i][j];
			if (good && _final[abs(j - n)][i] != _init[i][j])
			{
				good = false;
			}
		}
	}
	if (good)
	{
		return a + 1;
	}
	return spooky(_temp, _final, n, a + 1);
}
int main()
{
	int n;

	ofstream fout("transform.out");
	ifstream fin("transform.in");
	fin >> n;
	vector<vector<char>> _init(n, vector<char>(n));
	vector<vector<char>> _final(n, vector<char>(n));
	vector<vector<char>> _reflect(n, vector<char>(n));
	// Data entry
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char a;
			fin >> a;
			_init[i][j] = a;
		}
	}
	bool same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char a;
			fin >> a;
			_final[i][j] = a;
			if (same && a != _init[i][j]) same = false;
		}
	}
	if (same)
	{
		fout << "6" << "\n";
		return(0);
	}
	if (spooky(_init, _final, n, 0) != 0)
	{
		fout << spooky(_init, _final, n, 0) << "\n";
		return 0;
	}

	bool congruent = true;
	//checks for reflections
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			_reflect[i][n - j - 1] = _init[i][j];
			if (congruent && _final[n - i - 1][j] != _init[i][j])
			{
				congruent = false;
			}
		}
	}
	/*for (int i = 0; i < n; i++)
	{
	for (int j = 0; j < n; j++)
	{
	fout << _init[i][j] << "(" << i << "," << j << ")";
	}
	fout << "\n";
	}
	for (int i = 0; i < n; i++)
	{
	for (int j = 0; j < n; j++)
	{
	fout << _reflect[i][j];
	}
	fout << "\n";
	}*/
	if (congruent)
	{
		fout << "4" << "\n";
		return(0);
	}
	if (spooky(_reflect, _final, n, 0) != 0)
	{
		fout << "5" << "\n";
	}
	fout << "7" << "\n";
	return(0);
}
