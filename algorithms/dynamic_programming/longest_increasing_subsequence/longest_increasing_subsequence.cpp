#include <algorithm>
#include <iostream>
#include <vector>

#define INFINITY (1000000)

using namespace std;

int main() {

  uint64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (uint64_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int64_t> d(n - 1, INFINITY);
  int64_t position[n];
  int64_t previous[n - 1];

  int64_t length = 0;

  position[0] = -1;
  d[0] = -INFINITY;

  for (auto i = 0; i < n; i++) {
    auto temp = lower_bound(d.begin(), d.end(), a[i]);
    auto j = distance(d.begin(), temp);
    if (d[j - 1] < a[i] && a[i] < d[j]) {
      d[j] = a[i];
      position[j] = i;
      previous[i] = position[j - 1];
      length = max(length, j);
    }
  }

  vector<int64_t> ret;
  auto p = position[length];
  while (p != -1) {
    ret.push_back(a[p]);
    p = previous[p];
  }

  reverse(ret.begin(), ret.end());
  for (auto x : ret) {
    cout << x << " ";
  }
  cout << "\n";
}
