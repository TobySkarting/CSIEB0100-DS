#include <iostream>
#include "CircList.h"

using namespace std;

int main()
{
	CircList<int> intlist;
	intlist.Insert(5);
	intlist.Insert(15);
	intlist.Insert(25);
	intlist.Insert(35);
	cout << endl;
	cout << sum(intlist) << endl;
	intlist.Delete(20);
	intlist.Delete(15);
	intlist.Delete(35);
	cout << sum(intlist) << endl;
	CircList<char> charlist;
	charlist.Insert('d');
	charlist.Insert('c');
	charlist.Insert('b');
	charlist.Insert('a');
	charlist.Insert('a');
	charlist.Insert('a');
	cout << charlist << endl;
	charlist.Delete('e');
	charlist.Delete('c');
	cout << charlist << endl;
	cout << "Length: " << charlist.Length() << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << "At " << i << " is " << charlist.AtNth(i) << endl;
	}
	cout << "Delete 'a' for 2 times." << endl;
	charlist.DeleteAll(2, 'a');

	cout << charlist << endl;
	return 0;
}