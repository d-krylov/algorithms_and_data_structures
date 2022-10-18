#include <iostream>
#include <vector>

#define MAX_NODES (10000)

using namespace std;
using Node = vector<uint64_t>;

Node g[MAX_NODES];
bool v[MAX_NODES];

void DepthFirstSearch(uint64_t current) {
  v[current] = true;
  cout << "Visit vertex " << current << "\n";
  for (uint64_t node : g[current]) {
    if (!v[node]) {
      DepthFirstSearch(node);
    }
  }
  cout << "Exit vertex " << current << "\n";
}

int main() {

  uint64_t e;
  cin >> e;

  uint64_t a, b;
  for (auto i = 0; i < e; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  DepthFirstSearch(0);
  return 0;
}
