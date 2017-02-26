/*
ID: elu1
LANG: C++14
PROG: namenum
*/
#include <fstream>
#include <string>
using namespace std;


int main()
{
	string getConversion = "22233344455566670778889990";
	long long n;
	string line;
	ofstream fout("namenum.out");
	ifstream dictfile("dict.txt");
	ifstream fin("namenum.in");
	bool spooky = false;
	fin >> n;
	while (getline(dictfile, line))
	{
		string conversion;
		for (char c : line)
		{
			conversion += getConversion[c - 'A'];
		}
		if (stoll(conversion, nullptr) == n)
		{
			spooky = true;
			fout << line << "\n";
		}
	}
	if (!spooky)
	{
		fout << "NONE" << "\n";
	}
	return(0);
}

