#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int guess(int min, int max)
{
	static int just_for_init = ((int (__cdecl *)(unsigned int))&srand)(time(NULL));
	return min + rand() % (max - min + 1);
}

int main()
{
	cout << "Please determine a number between 1~100." << endl;

	string d;
	int count = 0;
	int left = 1, right = 100, mid;
	bool guessed = false;

	while (count++ < 4)
	{
		mid = (left + right) / 2;
		cout << "Is it between " << left << "~" << mid << "?(y/n)";
		cin >> d;
		if (d.front() == 'y')
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}

		cout << "Is it " << guess(left, right) << "?(y/n)";
		cin >> d;
		if (d.front() == 'y')
		{
			guessed = true;
			break;
		}
	}

	if (guessed)
	{
		cout << "Yes! I win." << endl;
	}
	else
	{
		cout << "Oh no... I lose..." << endl;
	}
	return 0;
}
