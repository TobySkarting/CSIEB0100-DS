#include <iostream>
#include "BQueue.h"

using namespace std;

int main()
{
	BQueue<int> bq(3);
	bq.Enque(1);
	bq.Enque(2);
	bq.Enque(3);
	bq.Enque(4);
	bq.Enque(5);
	for (int i = 0; i < 5; ++i)
		cout << bq.Deque() << " ";
	cout << endl;
	return 0;
}
