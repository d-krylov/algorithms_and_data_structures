#include <iostream>

#define N (16)

using namespace std;

int data[N];

int GetParent(int i) { return i - (i & (-i)); }

int GetNext(int i) { return i + (i & (-i)); }

int GetSum(int i) {
  int sum = 0;
  ++i;
  while (i > 0) {
    sum += data[i];
    i = GetParent(i);
  }
  return sum;
}

void update(int i, int v) {
  ++i;
  while (i < N) {
    data[i] += v;
    i = GetNext(i);
  }
}

int main() {

  int v[N];

  for (int i = 0; i < N; i++) {
    cin >> v[i];
    update(i, v[i]);
  }

  int k;
  cin >> k;
  cout << GetSum(k) << "\n";

  for (int i = 0; i < N; i++) {
    cout << data[i] << " ";
  }
  cout << "\n";

  return 0;
}
