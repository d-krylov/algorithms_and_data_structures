#include <iostream>

#define N (100)

using namespace std;

uint64_t n;
int64_t v[N];

void Heapify(int64_t i) {
  int64_t largest = i;
  int64_t left = 2 * i + 1;
  int64_t right = 2 * i + 2;

  if (left < n && v[left] > v[largest]) {
    largest = left;
  }
  if (right < n && v[right] > v[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(v[i], v[largest]);
    Heapify(largest);
  }
}

void BuildHeap() {
  for (int64_t i = n >> 1; i >= 0; i--) {
    Heapify(i);
  }
}

int main() {
  cin >> n;
  for (uint64_t i = 0; i < n; i++) {
    cin >> v[i];
  }
  BuildHeap();

  for (uint64_t i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";

  return 0;
}
