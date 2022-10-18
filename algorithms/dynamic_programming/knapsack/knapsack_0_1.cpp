#include <iostream>
#include <vector>

#define N (1000)
#define M (1000)

using namespace std;

int main() {
  uint64_t n;
  uint64_t capacity;

  cin >> n >> capacity;

  uint64_t c[n];
  uint64_t w[n];

  for (uint64_t i = 0; i < n; i++) {
    cin >> c[i] >> w[i];
  }

  uint64_t P[N][M];

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= capacity; j++) {
      if (w[i - 1] > j) {
        P[i][j] = P[i - 1][j];
      } else {
        P[i][j] = max(P[i - 1][j], P[i - 1][j - w[i - 1]] + c[i - 1]);
      }
    }
  }
  cout << P[n][capacity] << endl;
  return 0;
}
