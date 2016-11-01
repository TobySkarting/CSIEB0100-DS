#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_double_palindrome(string p)
{
	string r = p;
	reverse(r.begin(), r.end());
	if (r != p)
		return false;
	int mid = p.length() / 2;
	string m(p.begin(), p.begin() + mid);
	string n = m;
	reverse(n.begin(), n.end());
	if (n != m)
		return false;
	return true;
}

void check(string s);

int main()
{
	check("radarradar");
	check("madammadam");
	check("abcba");
	return 0;
}

void check(string s)
{
	if (is_double_palindrome(s))
		cout << s << " is a double palindrome." << endl;
	else
		cout << s << " is not a double palindrome." << endl;
}