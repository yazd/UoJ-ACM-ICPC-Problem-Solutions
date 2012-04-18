#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned int uint;

uint property(uint row, uint num) {
	return ((row-1) / num) % 2 + 1;
}

string getProperty(string cline, uint chosen) {

	string p1, p2;

	bool p1Quote = false;
	bool p2Quote = false;

	bool p1Start = false;
	bool p1End = false;
	bool p2Start = false;

	for (int i = 0; i < cline.length(); i++) {

		if (!p1Start) {
			if (cline[i] == ' ')
				continue;
			else if (cline[i] == '\"') {
				p1Start = true;
				p1Quote = true;
			} else {
				p1Start = true;
				p1.append(1, cline[i]);
			}
		} else {
			if (!p1End) {
				if (p1Quote) {
					if (cline[i] == '\"') {
						if (chosen == 1) return p1;
						p1End = true;
					} else {
						p1.append(1, cline[i]);
					}
				} else {
					if (cline[i] == ' ') {
						if (chosen == 1) return p1;
						p1End = true;
					} else {
						p1.append(1, cline[i]);
					}
				}
			} else {
				if (!p2Start) {
					if (cline[i] == ' ')
						continue;
					else if (cline[i] == '\"') {
						p2Start = true;
						p2Quote = true;
					} else {
						p2Start = true;
						p2.append(1, cline[i]);
					}
				} else {
					if (p2Quote) {
						if (cline[i] == '\"')
							return p2;
						else
							p2.append(1, cline[i]);
					} else {
						if (cline[i] == ' ') {
							return p2;;
						} else {
							p2.append(1, cline[i]);
						}
					}
				}
			}
		}
	}

	return p2;

}

string toLower(string text) {

	string res = "";

	for (int i = 0; i < text.length(); i++)
		res.append(1, tolower(text[i]));

	return res;

}

int main() {

	ifstream in;
	in.open("smarty.in");

	uint caseNumber = 0;

	while (true) {

		caseNumber++;

		int row, num;

		in >> row;

		if (row == 0) break;

		in >> num;

		string line;

		getline(in, line);

		uint chosen = property(row, num);
		string prop = getProperty(line, chosen);

		cout << caseNumber << ". " << toLower(prop) << endl;

	}

	return 0;
}
