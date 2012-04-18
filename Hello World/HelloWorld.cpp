#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {

	ifstream in;
	in.open("hello.in");

	int caseN = 0;

	while (true) {

		int n;
		in >> n;

		if (n < 0) break;

		caseN++;

		cout << "Case " << caseN << ": " << ceil(log2(n)) << endl;

	}

	return 0;

}

