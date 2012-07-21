#include <iostream>
using namespace std;

int main() {

  int fieldNo = 0;

  char field[101][101];

  while(true) {

    fieldNo++;

    int rows, cols;
    //n is rows, m is columns

    cin >> rows >> cols;

    if ((rows == 0) && (cols == 0)) break;

    int out[101][101] = {0};

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        cin >> field[y][x];
        if (field[y][x] == '*') {
          //there are 8 cells to increment

          if (y - 1 >= 0) {
            //can increment top
            out[y-1][x]++;
            if (x - 1 >= 0) out[y-1][x-1]++;
            if (x + 1 < cols) out[y-1][x+1]++;
          }

          if (y + 1 < rows) {
            //can increment bottom
            out[y+1][x]++;
            if (x - 1 >= 0) out[y+1][x-1]++;
            if (x + 1 < cols) out[y+1][x+1]++;
          }

          if (x - 1 >= 0) out[y][x-1]++; //increment left
          if (x + 1 < cols) out[y][x+1]++; //increment right

        }
      }
    }

    if (fieldNo > 1) cout << '\n';
    cout << "Field #" << fieldNo << ":\n";

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (field[y][x] == '*') {
          cout << field[y][x];
        } else {
          cout << out[y][x];
        }
      }
      cout << '\n';
    }

  }

  return 0;

}