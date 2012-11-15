#include <iostream>
#include <queue>
using namespace std;

struct Edge {
  int cost;
  int source;
  int dest;
  int addedCost;

  bool operator< (const Edge Edge2) const {
    return (this->cost + this->addedCost > Edge2.cost + Edge2.addedCost);
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

int *minCost;
bool *visited;
vector<int> *src;

int findBestPath(int start, int end, bool stopAtShortest = false) {

  minCost = new int[nCities];
  visited = new bool[nCities];
  src = new vector<int>[nCities];

  if (start == end) return 0;

  for (int i = 0; i < nCities; i++) {
    minCost[i] = -1;
    visited[i] = false;
  }

  minCost[start] = 0;
  src[start].push_back(start);

  priority_queue<Edge> q;
  
  int source = start;

  do {
    
    //cout << "Edges pushed from " << source << ": " << endl;

    for (int i = 0; i < edges[source].size(); i++) {
      if (!visited[edges[source][i].dest]) {
        edges[source][i].addedCost = minCost[source];
        //cout << edges[source][i].dest << " costing " << edges[source][i].cost << endl;
        q.push(edges[source][i]);
      }
    }
    
    visited[source] = true;

    if (q.empty()) break;
    Edge e = q.top();
    q.pop();

    //cout << "minCost edge: " << e.source << "-->" << e.dest << " costing " << e.cost << endl;

    if (minCost[e.dest] == -1 || e.cost + e.addedCost < minCost[e.dest]) {
      minCost[e.dest] = e.cost + e.addedCost;
      src[e.dest].push_back(e.source);

      if (stopAtShortest && e.dest == end) {
        break;
      }
      
    } else if (e.cost + e.addedCost == minCost[e.dest]) {
      src[e.dest].push_back(e.source);

      if (stopAtShortest && e.dest == end) {
        break;
      }

    } else {
      if (e.dest == end) break; //no need to continue, I got all my buddies
    }

    source = e.dest;

  } while (true);

  return -1;

}

int findAlmostBestPath(int start, int end) {

  //findAlmostBestPath()

}

void printPath(int start, int end, bool s = true) {

  if (start == end) return;
  if (s) cout << end;

  for (int i = 0; i < src[end].size(); i++) {
    cout << " <- " << src[end][i];
    printPath(start, src[end][i], false);
    if (s) cout << endl;
  }

}

void discardPath(int start, int end) {

  if (start == end) return;

  for (int i = 0; i < src[end].size(); i++) {

    int from = src[end][i];
    int to = end;

    for (int j = 0; j < edges[from].size(); j++) {
      if (edges[from][j].dest == to) {
        //cout << "Edge from " << from << " to " << to << " discarded" << endl;
        edges[from].erase(edges[from].begin() + j);
        break;
      }
    }

    discardPath(start, src[end][i]);

  }

}

int main() {

  while (true) {

    cin >> nCities;

    int nEdges;
    cin >> nEdges;

    if (nCities == 0 && nEdges == 0) break;

    int start, end;
    cin >> start >> end;

    edges = new vector<Edge>[nCities];

    for (int i = 0; i < nEdges; i++) {
      int n1, n2, cost;
      cin >> n1 >> n2 >> cost;
      edges[n1].push_back(Edge(cost, n1, n2));
    }
    
    findBestPath(start, end);
    //printPath(start, end);
    //cout << "-----------" << endl;

    int result = minCost[end];
    if (result >= 0) discardPath(start, end); //printPath(start, end);
    
    findBestPath(start, end, true);
    //printPath(start, end);
    //cout << "-----------" << endl;
    result = minCost[end];

    cout << result << endl;
    
    //cout << "----------" << endl;
  }

  return 0;
}