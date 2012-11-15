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

//int **edges;

int findBestPath(int start, int end) {

  if (start == end) return 0;

  int *min = new int[nCities];
  bool *visited = new bool[nCities];

  for (int i = 0; i < nCities; i++) {
    min[i] = -1;
    visited[i] = false;
  }

  min[start] = 0;

  priority_queue<Edge> q;
  
  int source = start;

  do {
    
    //cout << "Edges pushed from " << source + 1 << ": " << endl;

    for (int i = 0; i < edges[source].size(); i++) {
      if (!visited[edges[source][i].dest]) {
        edges[source][i].cost += min[source];
        //cout << edges[source][i].dest + 1 << " costing " << edges[source][i].cost << endl;
        q.push(edges[source][i]);
      }
    }
    
    edges[source].clear();
    visited[source] = true;

    if (q.empty()) break;
    Edge e = q.top();
    q.pop();

    //cout << "Min edge: " << e.source + 1 << "-->" << e.dest + 1 << " costing " << e.cost << endl;

    if (min[e.dest] == -1 || min[e.source] + e.cost < min[e.dest]) {
      min[e.dest] = e.cost;
      if (e.dest == end) return min[e.dest];
    }

    source = e.dest;


  } while (true);

  return -1;

}

int main() {

  int nCases = 0;
  cin >> nCases;

  while (nCases-- > 0) {

    cin >> nCities;

    int nEdges;
    cin >> nEdges;

    int start, end;
    cin >> start >> end;
    start--; end--;

    edges = new vector<Edge>[nCities];

    for (int i = 0; i < nEdges; i++) {
      int n1, n2, cost;
      cin >> n1 >> n2 >> cost;
      n1--;
      n2--;
      edges[n1].push_back(Edge(cost, n1, n2));
      edges[n2].push_back(Edge(cost, n2, n1));
    }
    
    int result = findBestPath(start, end);

    if (result == -1) {
      cout << "NONE" << endl;
    } else {
      cout << result << endl;
    }

    //cout << "----------" << endl;
  }

  return 0;
}