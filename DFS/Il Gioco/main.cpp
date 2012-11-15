#include <iostream>
#include <cstring>
using namespace std;

#define white false
#define black true

bool **board;
bool **visited;

bool *com_rows;

int size;

bool connectsBlackVertically(int row, int col) {

  int drow[] = {-1, -1, 0, 0, 1, 1};
  int dcol[] = {-1, 1, -1, 1, 0, 1};

  com_rows[row] = true;
  visited[row][col] = true;

  for (int i = 0; i < 6; i++) {
    int nrow = row + drow[i];
    int ncol = col + dcol[i];

    if (!(nrow >= 0 && nrow < size)) continue;
    if (!(ncol >= 0 && ncol < size)) continue;
    if (visited[nrow][ncol]) continue;

    if (board[nrow][ncol] == black) {
      connectsBlackVertically(nrow, ncol);
    }
  }

}

bool connectsVertically(int row, int col) {

  com_rows = new bool[size];
  memset(com_rows, 0, size);

  connectsBlackVertically(row, col);

  for (int i = 0; i < size; i++) {
    if (com_rows[i] == false) return false;
  }

  delete[] com_rows;
  return true;

}

bool getWinner() {

  visited = new bool*[size];
  for (int i = 0; i < size; i++) {
    visited[i] = new bool[size];
    memset(visited[i], 0, size);
  }

  for (int col = 0; col < size; col++) {

    if (board[0][col] == black) {
      if (connectsVertically(0, col)) return black;
    }

  }

  return white;

}

int main() {

  int t_case = 0;

  while (true) {

    cin >> size;
    if (size == 0) break;
    t_case++;

    board = new bool*[size];
    for (int i = 0; i < size; i++) {
      board[i] = new bool[size];
    }

    char c;

    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        cin >> c;

        if (c == 'b')
          board[row][col] = true;
        else
          board[row][col] = false;

      }
    }

    bool result = getWinner();

    cout << t_case << " " << (result == black ? "B" : "W") << endl;

    for (int i = 0; i < size; i++) {
      delete[] board[i];
    }

    delete[] board;

  }


}