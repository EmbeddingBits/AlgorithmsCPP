#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
      for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                  return i;
            }
      }
      return -1;
}

int main() {
      int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
      int n = sizeof(arr) / sizeof(arr[0]);

      int target = 6;

      int index = linearSearch(arr, n, target);

      if (index == -1) cout << "The element is not found";
      else cout << "The target " << target << " is found at index " << index;
}
