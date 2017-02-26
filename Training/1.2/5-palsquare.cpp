/*
ID: elu1
LANG: C++11
PROG: dualpal
*/
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
string longTostring(long number, int base)
{
	string s;
	while (number > 0)
	{
		char digit_char;
		int digit_int;
		digit_int = number % base;
		number = (number - digit_int) / base;
		if (digit_int < 10)
		{
			digit_char = 48 + digit_int;
		}
		else
		{
			digit_char = 'A' + digit_int - 10;
		}
		s = digit_char + s;
	}
	return s;
}
bool isPalin(string s)
{
	for (int i = 0; i < floor(s.size() / 2); i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	long s;
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	fin >> n >> s;
	for (long i = s + 1; n>0; i++)
	{
		int c = 0;
		for (long b = 2; b <= 10; b++)
		{
			if (c == 2)
			{
				break;
			}
			if (isPalin(longTostring(i, b)))
			{
				c++;
			}
		}
		if (c == 2)
		{
			n--;
			fout << i << "\n";
		}
	}
	return (0);
}


