#include <iostream>

using namespace std;

int calculate(char op, int op1, int op2)
{
	switch (op)
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		if (op2 == 0)
			throw "Divided by zero.";
		return op1 / op2;
	default:
		throw "Unknown operation.";
	}
}

int main()
{
	try
	{
		cout << "6 + 2 = ";
		cout << calculate('+', 6, 2) << endl;
	}
	catch (const char *e)
	{
		cout << e << endl;
	}

	try
	{
		cout << "6 - 2 = ";
		cout << calculate('-', 6, 2) << endl;
	}
	catch (const char *e)
	{
		cout << e << endl;
	}

	try
	{
		cout << "6 * 2 = ";
		cout << calculate('*', 6, 2) << endl;
	}
	catch (const char *e)
	{
		cout << e << endl;
	}

	try
	{
		cout << "6 / 2 = ";
		cout << calculate('/', 6, 2) << endl;
	}
	catch (const char *e)
	{
		cout << e << endl;
	}

	try
	{
		cout << "6 / 0 = ";
		cout << calculate('/', 6, 0) << endl;
	}
	catch (const char *e)
	{
		cout << e << endl;
	}

	try
	{
		cout << "6 $ 2 = ";
		cout << calculate('$', 6, 2) << endl;
	}
	catch (const char *e)
	{
		cout << e << endl;
	}

	return 0;
}
