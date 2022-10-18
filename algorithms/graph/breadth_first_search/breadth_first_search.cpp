#include <iostream>
#include <queue>
#include <vector>

#define MAX_NODES (10000)

using namespace std;
using Node = vector<uint64_t>;

Node g[MAX_NODES];
bool v[MAX_NODES];
queue<uint64_t> q;

void BreadthFirstSearch(uint64_t current) {
  q.push(current);
  v[current] = true;
  while (q.empty() == false) {
    auto c = q.front();
    cout << "Current is " << c << "\n";
    q.pop();
    for (auto x : g[c]) {
      if (!v[x]) {
        q.push(x);
        v[x] = true;
        cout << " Put " << x << "\n";
      }
    }
  }
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

  BreadthFirstSearch(0);
  return 0;
}
