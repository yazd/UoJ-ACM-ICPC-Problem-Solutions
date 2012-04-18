#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ifstream in;
	in.open("ean13.in");

	int nCases;
	in >> nCases;

newCase:
	while (true) {

		if (nCases == 0) break;
		nCases--;

		int num[13];
		int sumEven = 0;
		int sumOdd = 0;

		for (int i = 1; i <= 13; i++) {

			char c;
			in >> c;

			int n = c - '0';
			num[i-1] = n;

			if (i % 2 == 0) 
				sumEven += n;
			else
				sumOdd += n;

		}

		int result = sumOdd + 3 * sumEven;
		result = result % 10;

		if (result == 0)
			cout << "YES" << endl;
		else if (num[12] == (10 - result))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;

}