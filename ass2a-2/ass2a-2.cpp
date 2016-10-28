#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ARRAYSIZE(x) (sizeof(x)/sizeof(*x))

vector<int> setUnion(int setA[], size_t a, int setB[], size_t b)
{
	vector<int> va(setA, setA + a);
	vector<int> vb(setB, setB + b);
	vector<int> vc;
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	vector<int>::iterator ita = va.begin(), itb = vb.begin();
	while (true)
	{
		if (ita == va.end())
		{
			vc.insert(vc.end(), itb, vb.end());
			break;
		}
		if (itb == vb.end())
		{
			vc.insert(vc.end(), ita, va.end());
			break;
		}
		if (*ita < *itb)
			vc.push_back(*(ita++));
		else if (*itb < *ita)
			vc.push_back(*(itb++));
		else
		{
			vc.push_back(*ita);
			++ita;
			++itb;
		}
	}
	return vc;
}

vector<int> setIntersection(int setA[], size_t a, int setB[], size_t b)
{
	vector<int> va(setA, setA + a);
	vector<int> vb(setB, setB + b);
	vector<int> vc;
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	vector<int>::iterator ita = va.begin(), itb = vb.begin();
	while (ita != va.end() && itb != vb.end())
	{
		if (*ita < *itb)
			++ita;
		else if (*itb < *ita)
			++itb;
		else
		{
			vc.push_back(*ita);
			++ita;
			++itb;
		}
	}
	return vc;
}


int main()
{
	int setA[] = { 3, 5, 6, 8, 10 };
	int setB[] = { 1, 2, 3, 5, 10, 18 };
	
	cout << "set A: ";
	for (int i = 0; i < ARRAYSIZE(setA); ++i)
		cout << setA[i] << " ";
	cout << endl;

	cout << "set B: ";
	for (int i = 0; i < ARRAYSIZE(setB); ++i)
		cout << setB[i] << " ";
	cout << endl;

	vector<int> u = setUnion(setA, ARRAYSIZE(setA), setB, ARRAYSIZE(setB));
	cout << "Union: ";
	for (int v : u)
		cout << v << " ";
	cout << endl;

	vector<int> i = setIntersection(setA, ARRAYSIZE(setA), setB, ARRAYSIZE(setB));
	cout << "Intersection: ";
	for (int v : i)
		cout << v << " ";
	cout << endl;
	return 0;
}
