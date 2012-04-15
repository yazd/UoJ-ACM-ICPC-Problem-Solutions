#include <iostream>
#include <fstream>

using namespace std;

unsigned int size;

unsigned int index(unsigned int x, unsigned int y) {
	return x + y * size;
}

int main() {

	ifstream in;
	in.open("Magic.in");

	unsigned int t;
	in >> t;

	while(t-- > 0) {

		in >> size;

		int *sq = new int[size * size];

		for (unsigned int i = 0; i < size * size; i++) {
			in >> sq[i];
		}

		int gsum = 0;

		for (unsigned int i = 0; i < size; i++) {
			gsum += sq[i];
		}

		int sum = 0;

		for (unsigned int y = 1; y < size; y++) {
			for (unsigned int x = 0; x < size; x++) {
				sum += sq[index(x,y)];
			}

			if (sum != gsum) goto isNotMagic;

			sum = 0;

		}

		for (unsigned int x = 0; x < size; x++) {
			for (unsigned int y = 0; y < size; y++) {
				sum += sq[index(x,y)];
			}

			if (sum != gsum) goto isNotMagic;

			sum = 0;
		}

		for (unsigned int i = 0; i < size; i++) {
			sum += sq[index(i,i)];
		}

		if (sum != gsum) goto isNotMagic;

		sum = 0;

		for (unsigned int i = 0; i < size; i++) {
			sum += sq[index(i,i)];
		}

		if (sum != gsum) goto isNotMagic;

		isMagic:
		cout << "MAGIC WITH MAGIC NUMBER " << gsum << ".\n";
		goto nextTestCase;

		isNotMagic:
		cout << "NOT MAGIC.\n";

		nextTestCase:
		delete[] sq;

	}

	return 0;

}
