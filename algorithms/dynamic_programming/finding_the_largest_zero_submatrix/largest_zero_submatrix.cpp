#include <iostream>
#include <stack>
#include <vector>

#define W (10)
#define H (10)

using namespace std;

uint64_t M[H][W];
uint64_t ret;

void ZeroSubMatrix() {
  vector<int> d(W, -1);
  vector<int> d1(W);
  vector<int> d2(W);

  stack<int> s;
  for (uint64_t i = 0; i < H; ++i) {

    for (int j = 0; j < W; ++j) {
      if (M[i][j] == 1)
        d[j] = i;
    }

    for (int j = 0; j < W; ++j) {
      while (!s.empty() && d[s.top()] <= d[j]) {
        s.pop();
      }
      d1[j] = s.empty() ? -1 : s.top();
      s.push(j);
    }

    while (!s.empty()) {
      s.pop();
    }

    for (int j = W - 1; j >= 0; --j) {
      while (!s.empty() && d[s.top()] <= d[j]) {
        s.pop();
      }

      d2[j] = s.empty() ? W : s.top();
      s.push(j);
    }

    while (!s.empty()) {
      s.pop();
    }

    for (int j = 0; j < W; ++j) {
      ret = max(ret, (i - d[j]) * (d2[j] - d1[j] - 1));
    }
  }
}

int main() {

  for (uint64_t i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> M[i][j];
    }
  }

  ZeroSubMatrix();

  cout << ret << "\n";
  return 0;
}
