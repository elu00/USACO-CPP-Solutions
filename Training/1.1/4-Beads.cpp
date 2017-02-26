/*
ID: elu1
LANG: C++14
PROG: beads
*/
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	vector<vector<int>> groupings;
	int n;
	int most = 0;
	string necklace;
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	fin >> n >> necklace;
	char previous_color = 'p';
	//generates list of groupings of beads
	for (int i = 0; i < n; i++)
	{
		char current_color = necklace[i];
		if (current_color == previous_color)
		{
			groupings.back()[1] = i;
		}
		else if (current_color == 'w')
		{
			continue;
		}
		else
		{
			groupings.push_back({ i,i });
			previous_color = current_color;
		}
	}
	int groupings_size = static_cast<int>(groupings.size());
	if (groupings_size <= 2)
	{
		fout << n << "\n";
		return(0);
	}
	//checks for largest grouping without considering loopbacks
	for (int i = 0; i < groupings_size - 1; i++)
	{
		int min = (i == 0) ? 0 : (groupings[i - 1][1] + 1);
		int max = (i >= groupings_size - 2) ? groupings_size - 1 : groupings[i + 2][0] - 1;
		int size = max - min + 1;
		if (size > most)
		{
			most = size;
		}
	}
	//considers loopbacks
	//if number is even
	if ((groupings_size % 2) == 0)
	{
		int size = groupings[1][0] + n - groupings[groupings_size - 2][1] - 1;
		if (size > most)
		{
			most = size;
		}
	}
	//If size is odd, then opposite ends must be same color
	else
	{
		int size = groupings[2][0] + n - groupings[groupings_size - 2][1] - 1;
		if (size > most)
		{
			most = size;
		}
		size = groupings[1][0] + n - groupings[groupings_size - 3][1] - 1;
		if (size > most)
		{
			most = size;
		}
	}
	fout << most << "\n";
	return(0);
}

