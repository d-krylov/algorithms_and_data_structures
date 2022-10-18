#include <iostream>
#include <vector>

#define MAX_NODES (10000)

using namespace std;
using Node = vector<uint64_t>;

Node g[MAX_NODES];
bool v[MAX_NODES];
vector<uint64_t> component;

void DepthFirstSearch(uint64_t current) {
  v[current] = true;
  component.push_back(current);
  for (uint64_t node : g[current]) {
    if (!v[node]) {
      DepthFirstSearch(node);
    }
  }
}

void SearchConnectedComponents(uint64_t n) {
  for (uint64_t i = 0; i < n; ++i) {
    if (!v[i]) {
      component.clear();
      DepthFirstSearch(i);
      cout << "Component:";
      for (uint64_t x : component) {
        cout << " " << x;
      }
      cout << "\n";
    }
  }
}

int main() {

  uint64_t n;
  uint64_t e;
  cin >> n >> e;

  uint64_t a, b;
  for (auto i = 0; i < e; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  SearchConnectedComponents(n);
  return 0;
}
