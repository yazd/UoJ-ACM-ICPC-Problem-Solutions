#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ifstream in;
	in.open("doubles.in");

newCase:
	while (true) {

		bool nums[100];

		for (int i = 0; i < 100; i++) 
			nums[i] = false;

		while (true) {
			int n;
			in >> n;

			if (n == -1) goto endCases;
			if (n == 0) break;

			nums[n] = true;

		}

		int x = 0;

		for (int i = 0; i < 50; i++) {
			if (nums[i] & nums[2 * i])	x++;
		}

		cout << x << endl;

	}

endCases:
	return 0;

}