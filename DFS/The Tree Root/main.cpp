#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int size;

struct Node {
  int id;
  vector<int> con;
};

vector<Node> nodes;
map<int, int> cache;

bool *visited;

int getHeightReal(int node) {
  
  visited[node] = true;

  Node n = nodes[node];
  int maxHeight = 0;

  map<int, int>::iterator it;

  for (int i = 0; i < n.con.size(); i++) {
    if (!visited[n.con[i]]) {

      int h;

      it = cache.find(node * size + n.con[i]);
      if (it != cache.end()) {
        h = it->second;
      } else {
        h = getHeightReal(n.con[i]) + 1;
        cache[node * size + n.con[i]] = h;
      }
      
      //cout << "From node " << node << ", looking at node " << n.con[i] << ", cost: " << h << endl;
      if (h > maxHeight) maxHeight = h;
    }
  }

  return maxHeight;

}

int getHeight(int node) {

  memset(visited, 0, size);
  int h = getHeightReal(node);
  //cout << "Node " << node + 1 << ": " << h << endl;
  return h;

}


int main() {

  while (true) {

    if (!(cin >> size)) break;

    nodes.clear();
    cache.clear();
    
    for (int i = 0; i < size; i++) {
      int count;
      cin >> count;

      Node n;
      n.id = i;
      
      for (int j = 0; j < count; j++) {
        int s;
        cin >> s;
        n.con.push_back(s - 1);
      }

      nodes.push_back(n);

    }

    visited = new bool[size];

    vector<int> bestNodes;
    vector<int> worstNodes;

    int leastHeight = size + 1;
    int maxHeight = -1;

    for (int i = 0; i < size; i++) {

      int height = getHeight(i);
      if (height > maxHeight) {
        worstNodes.clear();
        worstNodes.push_back(i);
        maxHeight = height;
      } else if (height == maxHeight) {
        worstNodes.push_back(i);
        maxHeight = height;
      }

      if (height < leastHeight) {
        bestNodes.clear();
        bestNodes.push_back(i);
        leastHeight = height;
      } else if (height == leastHeight) {
        bestNodes.push_back(i);
        leastHeight = height;
      }

    }

    cout << "Best Roots  :";
    for (int i = 0; i < bestNodes.size(); i++) {
      cout << " " << bestNodes[i] + 1;
    }

    cout << endl;

    cout << "Worst Roots :";
    for (int i = 0; i < worstNodes.size(); i++) {
      cout << " " << worstNodes[i] + 1;
    }

    cout << endl;

  }

  return 0;

}