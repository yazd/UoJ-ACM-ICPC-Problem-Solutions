#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define PI 3.14159265

int main() {

	ifstream in;
	in.open("clock.in");

	int nCases;
	in >> nCases;

	int nCase = 0;

newCase:
	while (true) {

		if (nCases == nCase) break;
		nCase++;

		double h[2], m[2], s[2], u[2];

		in >> h[0] >> m[0] >> s[0] >> u[0];
		in >> h[1] >> m[1] >> s[1] >> u[1];

		double z1 = h[0] / 12.0 + m[0] / (12.0 * 60.0) + s[0] / (12.0 * 60.0 * 60.0) + u[0] / (12.0 * 60.0 * 60.0 * 100.0);
		double z2 = h[1] / 12.0 + m[1] / (12.0 * 60.0) + s[1] / (12.0 * 60.0 * 60.0) + u[1] / (12.0 * 60.0 * 60.0 * 100.0);

		double rad;
		in >> rad;

		/*double c1, c2;
		c1 = u[0] + s[0] * 100 + m[0] * 100 * 60 + h[0] * 100 * 60 * 60;

		c2 = u[1] + s[1] * 100 + m[1] * 100 * 60 + h[1] * 100 * 60 * 60;

		double total = 100 + 60 * 100 + 60 * 60 * 100 + 12 * 60 * 60 * 100;

		double p1 = PI / total * c1;
		double p2 = PI / total * c2;

		cout << p1 << endl;
		cout << p2 << endl;*/

		cout << nCase << ". ";
		printf("%.3f", (rad * rad * (z2 - z1) * PI));
		cout << endl;

	}

endCases:
	return 0;

}