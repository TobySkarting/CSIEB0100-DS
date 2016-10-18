#include <iostream>
#include <fstream>

using namespace std;

void histogram(int count)
{
	for (int i = 0; i != count; ++i)
		cout << '*';
}

int main()
{
	ifstream fin("input.txt");
	char ch;
	int counts[26 + 26] = { 0 };
	while (fin >> ch)
	{
		if (!isalpha(ch))
			continue;
		if (islower(ch))
			++counts[ch - 'a'];
		else
			++counts[26 + ch - 'A'];
	}
	for (int i = 0; i != 26; ++i)
		if (counts[i])
		{
			cout << static_cast<char>('a' + i) << "  ";
			histogram(counts[i]);
			cout << counts[i] << endl;
		}
	for (int i = 0; i != 26; ++i)
		if (counts[26 + i])
		{
			cout << static_cast<char>('A' + i) << "  ";
			histogram(counts[26 + i]);
			cout << counts[26 + i] << endl;
		}

    return 0;
}

