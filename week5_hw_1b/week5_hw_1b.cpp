#include <iostream>
#include <vector>

using namespace std;

vector<int> vA, vB, vC;

void printPegs()
{
	cout << "A";
	for (const int i : vA)
		cout << i;
	cout << endl;
	cout << "B";
	for (const int i : vB)
		cout << i;
	cout << endl;
	cout << "C";
	for (const int i : vC)
		cout << i;
	cout << endl;
}

void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		int d = -1;
		if (A == 'A')
		{
			d = vA.back();
			vA.pop_back();
		}
		else if (A == 'B')
		{
			d = vB.back();
			vB.pop_back();
		}
		else if (A == 'C')
		{
			d = vC.back();
			vC.pop_back();
		}
		if (C == 'A')
		{
			vA.push_back(d);
		}
		else if (C == 'B')
		{
			vB.push_back(d);
		}
		else if (C == 'C')
		{
			vC.push_back(d);
		}

		cout << "Move disk " << d << " from " << A << " to " << C << endl;
		printPegs();
	}
	else
	{
		hanoi(n - 1, A, C, B);
		hanoi(1, A, B, C);
		hanoi(n - 1, B, A, C);
	}
}

int main()
{
	int n;
	cout << "How many disks in peg A?";
	cin >> n;
	for (int i = n; i >= 1; --i)
		vA.push_back(i);
	cout << "Initial pegs" << endl;
	printPegs();
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
