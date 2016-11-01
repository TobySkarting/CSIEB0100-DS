#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string product(string a, string b)
{
	stringstream ssA(a), ssB(b);
	vector<string> vA, vB;
	string tmp;
	string result;
	while (ssA >> tmp)
		vA.push_back(tmp);
	while (ssB >> tmp)
		vB.push_back(tmp);
	for (string &j : vB)
		for (string &i : vA)
			result += i + j + " ";
	return result;
}

int main()
{
	cout << product("Now I see you", "me too") << endl;
	return 0;
}
