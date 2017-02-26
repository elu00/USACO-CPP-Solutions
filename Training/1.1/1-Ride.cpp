/*
ID: elu1
LANG: C++14
PROG: ride
*/
#include <string>
#include <fstream>
using namespace std;
int main()
{
	string first;
	string second;
	int a = 1;
	int b = 1;
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	fin >> first >> second;
	for(char C : first)
	{
		a = a*(C - 'A' + 1);
	}
	for(char C : second)
	{
		b = b*(C - 'A' + 1);
	}
	if((a-b)%47==0)
	{
		fout << "GO\n";
	}
	else
	{
		fout << "STAY\n";
	}
	return 0;
}