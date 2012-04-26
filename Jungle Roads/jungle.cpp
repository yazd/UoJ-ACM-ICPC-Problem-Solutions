#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef unsigned int uint;

struct Edge {
	uint city1;
	uint city2;
	uint cost;

	public:
	bool operator< (Edge const& other) const;

};


struct City {
	uint index;
	vector<Edge> edges;
};

bool Edge::operator< (Edge const& other) const {
	return (this->cost > other.cost);
}

int main() {

	ifstream in;
	in.open("jungle.in");

	if (!in) return 0;

	while (true) {

		uint nCities;
		in >> nCities;

		if (nCities == 0) break;

		bool* cityChecked = new bool[nCities];

		for (uint i = 0; i < nCities; i++)
			cityChecked[i] = false;

		City* city = new City[nCities];

		string foo;
		uint num;
		char cityName;

		for (uint i = 0; i < nCities - 1; i++) {
			city[i].index = i;

			in >> foo;

			in >> num;

			for (uint j = 0; j < num; j++) {

				in >> cityName;

				Edge e;
				e.city1 = i;
				e.city2 = cityName - 'A';

				uint cost;
				in >> cost;

				e.cost = cost;

				city[e.city1].edges.push_back(e);
				city[e.city2].edges.push_back(e);

			}

		}

		city[nCities - 1].index = nCities - 1;

		uint totalCost = 0;
		uint nCheckedCities = 0;

		priority_queue <Edge> edges;

		for (size_t ed = 0; ed < city[0].edges.size(); ed++) {
			edges.push(city[0].edges[ed]);
		}

		while (nCheckedCities < nCities) {

			Edge e = edges.top();
			edges.pop();

			if (cityChecked[e.city1] && cityChecked[e.city2]) continue;

			totalCost += e.cost;

			if (!cityChecked[e.city1]) {

				cityChecked[e.city1] = true;
				nCheckedCities ++;

				for (size_t ed = 0; ed < city[e.city1].edges.size(); ed++)
					edges.push(city[e.city1].edges[ed]);

			}

			if (!cityChecked[e.city2]) {

				cityChecked[e.city2] = true;
				nCheckedCities ++;

				for (size_t ed = 0; ed < city[e.city2].edges.size(); ed++)
					edges.push(city[e.city2].edges[ed]);


			}


		}

		cout << totalCost << endl;

	}

	return 0;
}

