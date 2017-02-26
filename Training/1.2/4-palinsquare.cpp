/*
ID: elu1
LANG: C++11
PROG: palsquare
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
    for (int i = 0; i<floor(s.size() / 2); i++)
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
    int b;
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    fin >> b;
    for (long i = 1; i <= 300; i++)
    {
        long s = i*i;
        //underscore denotes conversion to base b
        string _s = longTostring(s, b);
        if (isPalin(_s))
        {
            string _i = longTostring(i, b);
            fout << _i << " " << _s << "\n";
        }
    }
    return (0);
}

