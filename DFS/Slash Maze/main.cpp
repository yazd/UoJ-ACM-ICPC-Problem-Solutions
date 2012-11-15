#include <iostream>
#include <cstring>
using namespace std;

bool **d1blocked;
bool **d2blocked;

bool **visited;

int size;

int w, h;

bool valid(int d1, int d2) {
  int r = (d2 + h - d1 - 1) / 2;
  int c = (d1 + d2 - h + 1) / 2;
  return (r >= 0 && r < h && c >= 0 && c < w);
}

bool canMove(int sd1, int sd2, int dd1, int dd2) {
  if (sd1 == dd1) {
    if (sd2 < dd2) {
      return valid(dd1, dd2) && !d2blocked[sd1][sd2];
    } else {
      return valid(dd1, dd2) && !d2blocked[sd1][dd2];
    }
  } else { //sd2 == dd2
    if (sd1 < dd1) {
      return valid(dd1, dd2) && !d1blocked[sd1][sd2];
    } else {
      return valid(dd1, dd2) && !d1blocked[dd1][sd2];
    }
  }
}

int dd1[] = {0, 1, 0, -1};
int dd2[] = {-1, 0, 1, 0};

int findLoop(int d1, int d2, int ind1, int ind2) {

  visited[d1][d2] = true;

  for (int i = 0; i < 4; i++) {
    int nd1 = d1 + dd1[i];
    int nd2 = d2 + dd2[i];

    if (canMove(d1, d2, nd1, nd2)) {
      if (nd1 == ind1 && nd2 == ind2) {
        return 1;
      }

      if (visited[nd1][nd2]) continue;
      
      int result = findLoop(nd1, nd2, ind1, ind2);
      if (result == -1) return result;
      return result + 1;
    }
  }

  return -1;

}

int main() {

  int t_maze = 0;

  while (true) {

    int w, h;
    cin >> w >> h;

    size = w + h;
    if (size == 0) break;

    char c;

    t_maze++;

    d1blocked = new bool*[size * 2];
    d2blocked = new bool*[size * 2];
    visited = new bool*[size * 2];

    for (int i = 0; i < w + h; i++) {
      d1blocked[i] = new bool[size * 2];
      d2blocked[i] = new bool[size * 2];
      visited[i] = new bool[size * 2];

      memset(d1blocked, 0, size * 2);
      memset(d2blocked, 0, size * 2);
      memset(visited, 0, size * 2);
    }

    for (int row = 0; row < h; row++) {
      for (int col = 0; col < w; col++) {
        cin >> c;

        int d1, d2;
        d1 = col - row + h - 1;
        d2 = col + row;

        if (c == '\\') {
          d1blocked[d1][d2] = true;
          if (valid(d1, d2+1)) d1blocked[d1][d2 + 1] = true;
        } else {
          d2blocked[d1][d2] = true;
          if (valid(d1 + 1, d2)) d2blocked[d1 + 1][d2] = true;
        }
        
      }
    }

    int max = 0;
    int count = 0;

    for (int d1 = 0; d1 < size; d1++) {
      for (int d2 = 0; d2 < size; d2++) {
        if (visited[d1][d2]) continue;
        if (!valid(d1, d2)) continue;
        visited[d1][d2] = true;

        int len = findLoop(d1, d2, d1, d2);
        if (len > 1) {
          count++;
        }

        if (max < len) max = len;

      }
    }

    cout << "Maze #" << t_maze << ":" << endl;
    if (count > 0) {
      cout << count << " Cycles; the longest has length " << max << "." << endl;
      cout << endl;
    } else {
      cout << "There are no cycles." << endl;
      cout << endl;
    }

  }

  return 0;

}
