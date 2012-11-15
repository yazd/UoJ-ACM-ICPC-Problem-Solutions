#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

map<int, vector<int> > edges;
bool* visited;
bool* color;
bool result;

void findColor(int edge) {

  result = true;

  bool currentColor = false;

  stack<int> es;
  es.push(edge);
  
  color[edge] = currentColor;

  while (!es.empty()) {

    edge = es.top();
    es.pop();

    visited[edge] = true;

    currentColor = !color[edge];

    vector<int> near = edges[edge];
    for (vector<int>::iterator it = near.begin(); it < near.end(); it++) {
      
      int e2 = *it;
      
      #ifdef DEBUG
        cout << edge << " -> " << e2 << endl;
        cout << currentColor << endl;
      #endif

      if (visited[e2]) {
        if (color[e2] != currentColor) {
          #ifdef DEBUG
            cout << "problem?" << endl;
          #endif
          result = false;
          return;
        }
      } else {
        visited[e2] = true;
        color[e2] = currentColor;
        es.push(e2);
      }

    }

  }

}

int main() {

  while (true) {

    int n;
    cin >> n;

    if (n == 0) break;

    int e;
    cin >> e;

    visited = new bool[n];
    color = new bool[n];

    memset(visited, 0, n);
    memset(color, 0, n);

    edges.clear();

    for (int i = 0; i < e; i++) {
      int e1, e2;
      cin >> e1 >> e2;

      edges[e1].push_back(e2);
      edges[e2].push_back(e1);
    }

    #ifdef DEBUG
    for (int i = 0; i < e; i++) {
      cout << i << ": ";
      for (int j = 0; j < edges[i].size(); j++) {
        cout << edges[i][j] << ", ";
      }
      cout << endl;
    }
    #endif

    findColor(0);

    #ifdef DEBUG
    for (int i = 0; i < n; i++) {

      cout << i << ": ";

      if (visited[i]) {
        cout << color[i];
      } else {
        cout << "not visited";
      }

      cout << endl;
    }
    #endif

    if (result) {
      cout << "BICOLORABLE." << endl;
    } else {
      cout << "NOT BICOLORABLE." << endl;
    }

  }

  return 0;
}