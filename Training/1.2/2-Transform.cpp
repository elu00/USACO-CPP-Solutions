/*
ID: elu1
LANG: C++14
PROG: transform
*/
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
vector<vector<char>> rotate(vector<vector<char>> _init, int n)
{
	vector<vector<char>> _temp(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			_temp[i][j] = _init[n - j - 1][i];
		}
	}
	return _temp;
}
vector<vector<char>> reflect(vector<vector<char>> _init, int n)
{
	vector<vector<char>> _reflect(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			_reflect[i][j] = _init[i][n - j - 1];
		}
	}
	return _reflect;
}
bool CompareGraph(vector<vector<char>> first, vector<vector<char>> second, int n)
{
	bool r = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			r = (r && (first[i][j] == second[i][j]));
		}
	}
	return r;
}
void PrintGraph(vector<vector<char>> first, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << first[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	int n;
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	fin >> n;
	vector<vector<char>> _init(n, vector<char>(n));
	vector<vector<char>> _final(n, vector<char>(n));
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

	vector<vector<char>> _90deg = rotate(_init, n);
	vector<vector<char>> _180deg = rotate(_90deg, n);
	vector<vector<char>> _270deg = rotate(_180deg, n);
	if (CompareGraph(_90deg, _final, n))
	{
		fout << "1" << "\n";
		return 0;
	}
	if (CompareGraph(_180deg, _final, n))
	{
		fout << "2" << "\n";
		return 0;
	}
	if (CompareGraph(_270deg, _final, n))
	{
		fout << "3" << "\n";
		return 0;
	}
	//checking for reflections
	_init = reflect(_init, n);
	if (CompareGraph(_init, _final, n))
	{
		fout << "4" << "\n";
		return 0;
	}
	_90deg = rotate(_init, n);
	_180deg = rotate(_90deg, n);
	_270deg = rotate(_180deg, n);
	if (CompareGraph(_90deg, _final, n))
	{
		fout << "5" << "\n";
		return 0;
	}
	if (CompareGraph(_180deg, _final, n))
	{
		PrintGraph(_init, n);
		PrintGraph(_final, n);
		PrintGraph(_180deg, n);
		fout << "5" << "\n";
		return 0;
	}
	if (CompareGraph(_270deg, _final, n))
	{
		fout << "5" << "\n";
		return 0;
	}
	if (same)
	{
		fout << "6" << "\n";
		return(0);
	}
	fout << "7" << "\n";
	return(0);
}