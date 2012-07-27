#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {

  int testCases;
  cin >> testCases;
  int cTestCase = 0;
  cin.get();

  string line;
  getline(cin, line);

  while (cTestCase++ < testCases) {

    stringstream sst;

    bool* cont[101];
    int* pp[101];

    bool active[101];
    int penalties[101];
    int problems[101];

    for (int i = 0; i < 101; i++) {
      cont[i] = new bool[10];
      pp[i] = new int[10];
      for (int j = 0; j < 10; j++) {
        cont[i][j] = false;
        pp[i][j] = 0;
      }
      penalties[i] = 0;
      problems[i] = 0;
      active[i] = false;
    }

    while (cin.good()) {

      getline(cin, line);
      if (line.size() == 0) break;

      int contestant, problem, t;
      char result;

      //cout << "|" << line << endl;
      sst << line;
      sst >> contestant >> problem >> t >> result;

      active[contestant] = true;

      if (result == 'C')
        if (cont[contestant][problem] == false) {
          cont[contestant][problem] = true;
          problems[contestant] += 1;
          penalties[contestant] += t + pp[contestant][problem];
        }

      if (result == 'I')
        if (cont[contestant][problem] == false)
          pp[contestant][problem] += 20;

    }

    while (true) {

      int max = -1;
      int bestTime = -1;
      vector<int> currentBest;

      for (int i = 0; i < 101; i++) {
        if (active[i]) {
          if (problems[i] > max) {
            max = problems[i];
            bestTime = penalties[i];
            currentBest.clear();
            currentBest.push_back(i);
          } else if (problems[i] == max) {
            if (penalties[i] < bestTime) {
              max = problems[i];
              bestTime = penalties[i];
              currentBest.clear();
              currentBest.push_back(i);
            } else if (penalties[i] == bestTime) {
              currentBest.push_back(i);
            }
          }
        }
      }

      if (max == -1) break;
      for (vector<int>::iterator it = currentBest.begin(); it < currentBest.end(); it++) {
        int c = *it;
        cout << c << ' ' << problems[c] << ' ' << penalties[c] << '\n';
        active[c] = false;
      }

    }

    if (cTestCase < testCases) cout << '\n';

  }

  return 0;
}