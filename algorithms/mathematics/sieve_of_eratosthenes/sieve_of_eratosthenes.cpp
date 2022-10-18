#include <iostream>

#define N (100)

using namespace std;

uint8_t A[N] = {0};

void SieveOfEratosthenes() {
  for (int64_t i = 2; i * i < N; i++) {
    if (A[i] == 0) {
      for (int64_t j = i * i; j <= N; j += i) {
        A[j] = 1;
      }
    }
  }
}

int main() {

  SieveOfEratosthenes();

  for (int64_t i = 2; i < N; i++) {
    if (A[i] == 0) {
      cout << i << " ";
    }
  }
  cout << "\n";
  return 0;
}
