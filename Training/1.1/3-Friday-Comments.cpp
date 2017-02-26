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
	/*
	Storing # of occurences of each weekday in current_state. For desired output, indexed in this way.
	Sat = 0
	Sun = 1
	etc.
	First iteration should be 0 mod 7
	*/
	vector<int> current_state(7, 0);
	int n;
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	fin >> n;
	int current = 0;
	//iterate through first n years starting with 1900
	for (int year = 1900; year < 1900 + n; year++)
	{
		int days;
		//iterate through months
		for (size_t i = 1; i <= 12; i++)
		{
			//Feburary
			if (i == 2)
			{
				//Conditionals for if it's a leap year. If it is, then the number of days between Feb 13th and Mar 13th will be 29, which simply shifts the day of the week over by 29 (mod 7) = 1
				if (year % 4 == 0 && ((!(year % 100 == 0)) || (year % 400 == 0)))
				{
					days = 1;
				}
				//If not leap year, Feb 13th and Mar 13th same day of week
				days = 0;
			}
			//30 day months that shift day of week over by 2
			else if (i == 4 || i == 6 || i == 9 || i == 11)
			{
				days = 2;
			}
			//31 day months
			else
			{
				days = 3;
			}
			//shift over the day of the week (stored in current) and increment the corresponding vector entry by 1
			current = (current + days) % 7;
			current_state[current] = current_state[current] + 1;
		}
	}
	//extraneous entry for January of year after this one
	current_state[current] = current_state[current] - 1;
	//First January 13th not considered
	current_state[0] = current_state[0] + 1;
	//print out days in desired format
	for (size_t i = 0; i < 6; i++)
	{
		fout << current_state[i] << ' ';
	}
	fout << current_state[6] << "\n";
	return 0;
}

