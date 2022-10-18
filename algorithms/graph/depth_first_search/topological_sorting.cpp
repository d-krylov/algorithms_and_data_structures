#include <algorithm>
#include <iostream>
#include <vector>

#define MAX_NODES (10000)

using namespace std;
using Node = vector<uint64_t>;

Node g[MAX_NODES];
bool v[MAX_NODES];

vector<uint64_t> ret;

void DepthFirstSearch(uint64_t current) {
  v[current] = true;
  for (uint64_t node : g[current]) {
    if (!v[node]) {
      DepthFirstSearch(node);
    }
  }
  ret.push_back(current);
}

void TopologicalSort(uint64_t n) {
  for (int i = 0; i < n; ++i) {
    if (!v[i]) {
      DepthFirstSearch(i);
    }
  }
  reverse(ret.begin(), ret.end());
}

int main() {

  uint64_t n;
  uint64_t e;
  cin >> n >> e;

  uint64_t a, b;
  for (auto i = 0; i < e; i++) {
    cin >> a >> b;
    g[a].push_back(b);
  }

  TopologicalSort(n);

  for (uint64_t i = 0; i < n; i++) {
    cout << i << " in " << ret[i] << "\n";
  }
  return 0;
}
