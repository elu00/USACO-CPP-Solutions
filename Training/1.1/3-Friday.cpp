/*
ID: elu1
LANG: C++14
PROG: friday
*/

#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");

	vector<int> current_state(7, 0);
	int n;
	fin >> n;
	int current = 0;
	for (int year = 1900; year < 1900 + n; year++)
	{
		int days;
		for (int i = 1; i <= 12; i++)
		{
			++current_state[current];
			if (i == 2)
			{
				days = 0;
                if (year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0)))
				{
					days = 1;
				}
			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				days = 2;
			}
			else
			{
				days = 3;
			}
            current += days;
            current %= 7;
		}
	}
	for (size_t i = 0; i < 6; i++)
	{
		fout << current_state[i] << ' ';
	}
	fout << current_state[6] << "\n";
	return 0;
}