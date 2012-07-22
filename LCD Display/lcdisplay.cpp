#include <iostream>
#include <bitset>

#include <string>
using namespace std;

int main() {

  int rep[] = {1 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5,
               1 | 1 << 1,
               1 |          1 << 2 | 1 << 3 |          1 << 5 | 1 << 6,
               1 | 1 << 1 | 1 << 2 |                   1 << 5 | 1 << 6,
               1 | 1 << 1 |                   1 << 4 |          1 << 6,
                   1 << 1 | 1 << 2 |          1 << 4 | 1 << 5 | 1 << 6,
                   1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6,
               1 | 1 << 1 |                            1 << 5,
               1 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6,
               1 | 1 << 1 | 1 << 2 |          1 << 4 | 1 << 5 | 1 << 6
              };

  while (true) {
    unsigned int length;
    string number;

    cin >> length;
    cin >> number;
    if (length == 0) break;

    for (int i = 0; number[i] != '\0'; i++) {
      int p = rep[number[i] - '0'];

      cout << ' ';
      if (i > 0) cout << ' ';
      if (p & (1 << 5))
        for (int x = 0; x < length; x++) cout << '-';
      else
        for (int x = 0; x < length; x++) cout << ' ';
      cout << ' ';
    }

    cout << '\n';

    for (int rows = 0; rows < length; rows++) {
      for (int i = 0; number[i] != '\0'; i++) {
        int p = rep[number[i] - '0'];

        if (i > 0) cout << ' ';
        if (p & (1 << 4)) cout << '|'; else cout << ' ';
        for (int x = 0; x < length; x++) cout << ' ';
        if (p & (1)) cout << '|'; else cout << ' ';
      }

      cout << '\n';
    }


    for (int i = 0; number[i] != '\0'; i++) {
      int p = rep[number[i] - '0'];

      cout << ' ';
      if (i > 0) cout << ' ';
      if (p & (1 << 6))
        for (int x = 0; x < length; x++) cout << '-';
      else
        for (int x = 0; x < length; x++) cout << ' ';
      cout << ' ';
    }

    cout << '\n';

    for (int rows = 0; rows < length; rows++) {
      for (int i = 0; number[i] != '\0'; i++) {
        int p = rep[number[i] - '0'];

        if (i > 0) cout << ' ';
        if (p & (1 << 3)) cout << '|'; else cout << ' ';
        for (int x = 0; x < length; x++) cout << ' ';
        if (p & (1 << 1)) cout << '|'; else cout << ' ';
      }

      cout << '\n';

    }

    for (int i = 0; number[i] != '\0'; i++) {
      int p = rep[number[i] - '0'];

      cout << ' ';
      if (i > 0) cout << ' ';
      if (p & (1 << 2))
        for (int x = 0; x < length; x++) cout << '-';
      else
        for (int x = 0; x < length; x++) cout << ' ';
      cout << ' ';
    }

    cout << '\n';

  }

  return 0;
}