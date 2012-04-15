#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream in;
	in.open("reverse.in");

	unsigned int test;
	in >> test;

	string str;
	getline(in, str); //to get rid of last /n

	while (test-- > 0) {

		getline(in, str);

		for (size_t i = str.length(); i > 0; i--) {
			cout << str[i-1];
		}

		cout << '\n';

	}

	return 0;

}

