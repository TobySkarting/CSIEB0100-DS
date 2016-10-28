#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool wordSetEqual(vector<string> setA, vector<string> setB)
{
	sort(setA.begin(), setA.end());
	setA.erase(unique(setA.begin(), setA.end()), setA.end());
	sort(setB.begin(), setB.end());
	setB.erase(unique(setB.begin(), setB.end()), setB.end());
	return equal(setA.begin(), setA.end(), setB.begin(), setB.end());
}

template<typename Container, typename Iterator>
bool in_quote(const Container& cont, const Iterator& it)
{
	return std::search(cont.begin(), cont.end(), it, it + 1) != cont.end();
}

bool isSubSet(vector<string> superSet, vector<string> subSet)
{
	for (vector<string>::iterator it = subSet.begin(); it != subSet.end(); ++it)
		if (!in_quote(superSet, it))
			return false;
}

int compareWordSets(vector<string> setA, vector<string> setB)
{
	sort(setA.begin(), setA.end());
	setA.erase(unique(setA.begin(), setA.end()), setA.end());
	sort(setB.begin(), setB.end());
	setB.erase(unique(setB.begin(), setB.end()), setB.end());
	if (equal(setA.begin(), setA.end(), setB.begin(), setB.end()))
		return 0;
	if (isSubSet(setA, setB))
		return 1;
	else if (isSubSet(setB, setA))
		return -1;
	return INT_MAX;
}

string getSetCompareMessage(int status)
{
	switch (status)
	{
	case 0:
		return "the same as";
	case 1:
		return "a proper superset of";
	case -1:
		return "a proper subset of";
	case INT_MAX:
		return "incomparable to";
	default:
		return "unknown";
	}
}

void printSet(vector<string> &set)
{
	for (string &s : set)
		cout << s << " ";
}

int main()
{
	vector<string> setA{ "to", "be", "or", "not", "to", "be" };
	vector<string> setB{ "or", "not", "to", "be" };
	vector<string> setC{ "not", "to", "be" };
	vector<string> setD{ "not", "to", "go" };

	cout << "setA: ";
	printSet(setA);
	cout << endl;

	cout << "setB: ";
	printSet(setB);
	cout << endl;

	cout << "setC: ";
	printSet(setC);
	cout << endl;

	cout << "setD: ";
	printSet(setD);
	cout << endl;

	cout << "setA and setB are " << (wordSetEqual(setA, setB) ? "" : "not ") << "equal." << endl;
	cout << "setA and setC are " << (wordSetEqual(setA, setC) ? "" : "not ") << "equal." << endl;

	cout << "setA is " << getSetCompareMessage(compareWordSets(setA, setB)) << " setB." << endl;
	cout << "setA is " << getSetCompareMessage(compareWordSets(setA, setC)) << " setC." << endl;
	cout << "setB is " << getSetCompareMessage(compareWordSets(setB, setC)) << " setC." << endl;
	cout << "setC is " << getSetCompareMessage(compareWordSets(setC, setA)) << " setA." << endl;
	cout << "setC is " << getSetCompareMessage(compareWordSets(setC, setB)) << " setB." << endl;
	cout << "setC is " << getSetCompareMessage(compareWordSets(setC, setD)) << " setD." << endl;

	return 0;
}
