#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX_ARRAY_SIZE 10

int A[MAX_ARRAY_SIZE];
int B[MAX_ARRAY_SIZE];
int C[MAX_ARRAY_SIZE];

void random_sum()
{
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		int a = -1, b = -1, posA, posB;
		while (a == -1)
		{
			posA = rand() % MAX_ARRAY_SIZE;
			a = A[posA];
		}
		while (b == -1)
		{
			posB = rand() % MAX_ARRAY_SIZE;
			b = B[posB];
		}
		C[i] = a + b;
		A[posA] = -1;
		B[posB] = -1;
	}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		A[i] = rand() % 100;
		B[i] = rand() % 100;
		C[i] = 0;
	}
	random_sum();
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
		cout << C[i] << " ";
	cout << endl;
	return 0;
}
