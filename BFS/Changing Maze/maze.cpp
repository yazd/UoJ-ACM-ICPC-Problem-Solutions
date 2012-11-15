#include <iostream>
#include <queue>
#include <map>
using namespace std;

int rows, cols, patterns;
bool*** boards;

map<int, map<int, map<int, bool> > > visited;

struct State {
  int row;
  int col;
  int pattern;
  int moves;
};

inline bool isVisited(State* state) {
  bool* result = &visited[state->pattern][state->row][state->col];
  if (*result) return true;
  *result = true;
  return false;
}

int findWay() {

  State init = {0, 0, 0, 0};

  queue<State> states;
  states.push(init);

  visited.clear();

  while (!states.empty()) {

    State state = states.front();
    states.pop();

    if (isVisited(&state)) continue;

    int rd[5] = {0, 1, 0, -1, 0};
    int cd[5] = {1, 0, -1, 0, 0};
    
    for (int i = 0; i < 5; i++) {

      int row = state.row + rd[i];
      int col = state.col + cd[i];

      if (row < 0) continue;
      if (row >= rows) continue;

      if (col < 0) continue;
      if (col >= cols) continue;

      int next_pattern = (state.pattern + 1) % patterns;
      if (boards[next_pattern][row][col]) continue;

      int moves = state.moves + 1;

      if (row == rows - 1 && col == cols - 1) {
        return moves;
      }

      State new_state = {row, col, next_pattern, moves};
      states.push(new_state);

    }

  }

  return -1;

}

int main() {

  int testCase = 0;

  while (true) {

    cin >> rows >> cols >> patterns;

    if (rows == 0 || cols == 0 || patterns == 0) break;

    testCase++;

    boards = new bool**[patterns];
    for (int p = 0; p < patterns; p++) {
      boards[p] = new bool*[rows];
      for (int row = 0; row < rows; row++) {
        boards[p][row] = new bool[cols];

        char input;
        for (int col = 0; col < cols; col++) {
          cin >> input;
          bool boundary = (input == '1');
          boards[p][row][col] = boundary;
        }
      }
    }

    int result = findWay();

    cout << "Case " << testCase << ": ";

    if (result >= 0) {
      cout << "Luke and Leia can escape in " << result << " steps." << endl;
    } else {
      cout << "Luke and Leia cannot escape." << endl;
    }

  }

}