// Reeeee.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout("circlecross.out");
	ifstream fin("circlecross.in");
	vector<char> alphabet = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	vector<vector<int>> indexes = { {-1},{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 },{ -1 }};
	int crossings = 0;
	for (int i = 0; i <= 51; i++)
	{
		int place = 5;
		char thing;
		fin >> thing;
		for (int j = 0; j <= 25; j++)
		{
			char boop = alphabet[j];
			if (boop == thing)
			{
				place = j;
				break;
			}
		}
		indexes[place].push_back(i);
	}
	for (int i = 0; i <= 25; i++)
	{
		for (int j = i+1; j <= 25; j++)
		{
			int x1 = indexes[i][1];
			int x2 = indexes[i][2];
			int y1 = indexes[j][1];
			int y2 = indexes[j][2];
			if ((y1>x1 && y1<x2)^(y2>x1 && y2<x2))
			{
				crossings++;
			}
		}
	}
	fout << crossings;
	return 0;
}

