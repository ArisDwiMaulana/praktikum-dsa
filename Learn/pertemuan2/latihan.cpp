#include <iostream>

using namespace std;

void min_max(int arr[], int n, int *terbesar, int *terkecil) {
  *terbesar = arr[0];
  *terkecil = arr[0];

  for (int i = 0; i < n; i++) {
    if (*terbesar < arr[i]) {
      *terbesar = arr[i];
    }

    if (*terkecil > arr[i]) {
      *terkecil = arr[i];
    }
  }
}

int main() {
  int angka[5] = {20, 10, 40, 60, 70};
  int min;
  int max;
  min_max(angka, 5, &max, &min);

  cout << "terbesar " << max << endl;
  cout << "terkecil " << min << endl;
  return 0;
}
