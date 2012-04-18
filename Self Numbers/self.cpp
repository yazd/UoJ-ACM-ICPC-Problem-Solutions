#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int sum(int num) {

	string s;
	stringstream out;
	out << num;
	s = out.str();

	int sum = 0;

	for (unsigned int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}

	return sum;
}

int main() {

	ifstream in;
	in.open("self.in");

	unsigned int max;
	in >> max;

	bool* generated = new bool[max];

	for(unsigned int i = 0; i < max; i++) {
		generated[i] = false;
	}

	for (unsigned int i = 0; i < max; i++) {

		unsigned int res = i + sum(i);

		if (res >= max) continue;
		generated[res] = true;

	}

	for (unsigned int i = 0; i < max; i++) {
		if (!generated[i])
			cout << i << endl;
	}

	return 0;
}
