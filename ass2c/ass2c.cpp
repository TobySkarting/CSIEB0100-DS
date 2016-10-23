#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

bool compress_file(const string &fileName)
{
	string s;
	stringstream ss;
	ifstream fin(fileName);
	if (!fin)
		return false;
	
	char ch, last = NULL;
	int count = 1;
	while (fin.get(ch))
	{
		if (ch == last)
			++count;
		else
		{
			if (count > 1)
				ss << count;
			last = ch;
			count = 1;
			ss << ch;
		}
	}
	if (count > 1)
		ss << count;

	ofstream fout(fileName);
	fout << ss.str();
	fout.close();
	return true;
}

size_t file_size(const string &fileName)
{
	ifstream fin(fileName);
	if (!fin)
		return 0;
	fin.seekg(0, SEEK_END);
	return fin.tellg();
}

int main()
{
	const string fileName = "input.txt";
	size_t uncompressed_size = file_size(fileName);
	if (!compress_file(fileName))
	{
		cout << "Error." << endl;
		return -1;
	}
	size_t compressed_size = file_size(fileName);
	cout << "Successfully compressed. ratio: " << (double)uncompressed_size / compressed_size << endl;
	return 0;
}
