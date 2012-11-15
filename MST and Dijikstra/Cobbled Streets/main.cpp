#include <iostream>
#include <queue>
using namespace std;

struct Edge {
  int cost;
  int source;
  int dest;
  
  bool operator< (const Edge Edge2) const {
    return (this->cost > Edge2.cost);
  }

  Edge (int cost, int source, int dest) {
    this->cost = cost;
    this->source = source;
    this->dest = dest;
  }
};

int nCities;

vector<Edge> *edges;

bool *visited;
int nVisited;

int findMST() {

  nVisited = 0;
  visited = new bool[nCities];

  for (int i = 0; i < nCities; i++) {
    visited[i] = false;
  }

  int totalCost = 0;
  priority_queue<Edge> q;

  for (int i = 0; i < edges[0].size(); i++) {
    q.push(edges[0][i]);
  }

  while (!q.empty()) {

    Edge e = q.top();
    q.pop();

    //cout << "edge from " << e.source << " to " << e.dest << " with cost " << e.cost << " was taken." << endl;

    bool count = false;

    if (!visited[e.source]) {
      count = true;
      visited[e.source] = true;
      nVisited++;
    }

    if (!visited[e.dest]) {
      count = true;
      visited[e.dest] = true;
      nVisited++;

      for (int i = 0; i < edges[e.dest].size(); i++) {
        q.push(edges[e.dest][i]);
      }

    }

    if (count) totalCost += e.cost;
    if (nVisited == nCities) break;

  }
  
  return totalCost;

}

int main() {

  int nCases;
  cin >> nCases;

  while (nCases-- > 0) {

    int price;
    cin >> price;

    cin >> nCities;

    int nEdges;
    cin >> nEdges;

    edges = new vector<Edge>[nCities];

    for (int i = 0; i < nEdges; i++) {
      int n1, n2, cost;
      cin >> n1 >> n2 >> cost;
      n1--; n2--;
      edges[n1].push_back(Edge(cost, n1, n2));
      edges[n2].push_back(Edge(cost, n2, n1));
    }
    
    int result = findMST();
    cout << result * price << endl;
    
  }

  return 0;
}