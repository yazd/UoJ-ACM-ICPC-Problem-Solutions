#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned int uint;

int main() {

	ifstream in;
	in.open("circleland.in");

	if (!in) return 0;

	int cases;
	in >> cases;

	while (true) {
		if (cases == 0) break;
		cases--;

		uint num;
		in >> num;

		uint* l = new uint[num];

		uint total = 0;

		for (uint i = 0u; i < num; i++) {
			in >> l[i];
			total += l[i];
		}

		uint lsum = 0;
		uint rsum = total;

		uint min = total;

		for (uint i = 0u; i < num; i++) {

			if (i == 0)
				lsum = 0;
			else
				lsum = lsum + l[i-1];

			//cout << i << ": " << lsum << ", ";

			rsum = rsum - l[i];

			//cout << rsum << endl;
			uint res = lsum * 2 + rsum;

			if (res < min) min = res;

			res = rsum * 2 + lsum;

			if (res < min) min = res;

		}

		if (total - l[0] < min) min = total - l[0];
		if (total - l[num] < min) min = total - l[num];

		cout << min << endl;

	}

	return 0;
}

