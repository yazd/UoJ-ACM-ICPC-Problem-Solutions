#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {

	ifstream in;
	in.open("alaska.in");

	int nStations;

	while (true) {

		newCase:
		in >> nStations;
		if (nStations == 0) break;

		vector <int> stations;

		int station;

		for (int i = 0; i < nStations; i++) {
			in >> station;
			stations.push_back(station);
		}

		sort(stations.begin(), stations.end());

		if (stations[0] > 0) {
			cout << "IMPOSSIBLE" << endl;
			goto newCase;
		}

		for (int i = 1; i < nStations; i++) {
			if (stations[i] - stations[i-1] > 200) {
				cout << "IMPOSSIBLE" << endl;
				goto newCase;
			}
		}

		if (1422 - stations[nStations - 1] > 100) {
			cout << "IMPOSSIBLE" << endl;
			goto newCase;
		}

		cout << "POSSIBLE" << endl;

	}

	return 0;

}

