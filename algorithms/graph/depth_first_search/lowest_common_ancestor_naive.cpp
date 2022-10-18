#include <iostream>
#include <vector>

#define MAX_NODES (10000)

using namespace std;
using Node = vector<uint64_t>;

Node g[MAX_NODES];
bool v[MAX_NODES];
uint64_t depth[MAX_NODES];
uint64_t parent[MAX_NODES];

void DepthFirstSearch(uint64_t current, uint64_t d) {
  v[current] = true;
  depth[current] = d;
  for (uint64_t node : g[current]) {
    if (!v[node]) {
      DepthFirstSearch(node, d + 1);
      parent[node] = current;
    }
  }
}

uint64_t LowestCommonAncestor(uint64_t a, uint64_t b) {
  auto h1 = depth[a];
  auto h2 = depth[b];

  while (h1 != h2) {
    if (h1 > h2) {
      a = parent[a];
      h1 = h1 - 1;
    } else {
      b = parent[b];
      h2 = h2 - 1;
    }
  }
  while (a != b) {
    a = parent[a];
    b = parent[b];
  }
  return a;
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

  DepthFirstSearch(0, 0);
  cin >> a >> b;
  cout << LowestCommonAncestor(a, b) << "\n";
  return 0;
}
