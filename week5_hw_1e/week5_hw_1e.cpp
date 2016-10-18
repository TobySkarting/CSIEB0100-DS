#include <iostream>
#include <sys/timeb.h>

using namespace std;

void magic(int n)
// create a magic square of size n, n is odd
{
	const int MaxSize = 51; // maximum square size
	int square[MaxSize][MaxSize], k, l;

	// check correctness of n
	if ((n > MaxSize) || (n < 1)) { cerr << "Error!..n out of range \n"; return; }
	else if (!(n % 2)) { cerr << "Error!..n is even \n"; return; }

	// n is odd. Coxeter's rule can be used
	for (int i = 0; i < n; i++) // initialize square to 0
		for (int j = 0; j < n; j++)
			square[i][j] = 0;
	square[0][(n - 1) / 2] = 1; // middle of first row

								// i and j are current position
	int key = 2, i = 0; int j = (n - 1) / 2;
	while (key <= n*n) {
		// move up and left
		if (i - 1 < 0)  k = n - 1; else k = i - 1;
		if (j - 1 < 0)  l = n - 1; else l = j - 1;
		if (square[k][l])  i = (i + 1) % n;
		else { // square[k][l] is unoccupied
			i = k;
			j = l;
		}
		square[i][j] = key;
		key++;
	} // end of while

	// output the magic square
	/*
	cout << "magic square of size " << n << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << square[i][j] << " ";
		cout << endl;
	}
	*/
}

int main()
{
	const int m[] = { 5, 7, 9, 11 };
	const int times[] = { 50000, 100000, 500000 };
	struct timeb start, stop;

	for (const int time : times)
	{
		cout << "Iterations: " << time << endl;
		cout << "n\tms per iteration" << endl;
		for (const int n : m)
		{
			ftime(&start);
			// Start
			for (int i = 0; i < time; ++i)
				magic(n);
			// End
			ftime(&stop);
			cout << n << "\t" << double((stop.time - start.time) * 1000 + (stop.millitm - start.millitm)) / time << endl;
		}
		cout << endl;
	}
	return 0;
}
