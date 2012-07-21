#include <iostream>
using namespace std;

int main() {

  int nTest = 0;
  cin >> nTest;

  int testCase = 0;

  while (++testCase <= nTest) {

    double a[4], b[4], c[4];
    for (int i = 0; i < 4; i++) {
      cin >> a[i] >> b[i] >> c[i];
    }

    double T, V;
    cin >> T >> V;

    bool result = true;

    result = result && (a[0] * T + b[0] * V >= c[0]);
    result = result && (a[1] * T + b[1] * V >= c[1]);
    result = result && (a[2] * T + b[2] * V <= c[2]);
    result = result && (a[3] * T + b[3] * V <= c[3]);

    cout << testCase << ' ' << (result ? "SAFE" : "UNSAFE") << '\n';

  }

  return 0;

}