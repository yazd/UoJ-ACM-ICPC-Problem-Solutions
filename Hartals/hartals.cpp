#include <iostream>
using namespace std;

int main() {

  int test_cases;
  cin >> test_cases;

  while (test_cases-- > 0) {

    int n, p;
    cin >> n >> p;

    bool s[3651];
    for (int i = 0; i < 3651; i++) s[i] = false;

    for (int i = 0; i < p; i++) {
      int h;
      cin >> h;
      for (int j = h; j <= n; j+=h) {
        s[j] = (j % 7 > 0) && (j % 7 < 6);
      }
    }

    int count = 0;
    for (int i = 0; i <= n; i++)
      if (s[i])
        count++;

    cout << count << endl;

  }

  return 0;
}