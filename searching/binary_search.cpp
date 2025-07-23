#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int n) {
      int low = 0;
      int high = n - 1;

      while(low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                  return mid;
            }
            else if (arr[mid] < target) {
                  low = mid + 1;
            }
            else {
                  high = mid - 1;
            }
      }
      return -1;
}

void bubbleSort(int arr[], int n) {
      for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                  if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j+1] = temp;
                  }
            }
      }
}

int main() {
      int arr[] = {12, 23, 34, 45, 56, 67, 78, 90};
      int target = 56;
      int n = sizeof(arr) / sizeof(arr[0]);

      bubbleSort(arr, n);

      int index = binarySearch(arr, target, n);

      if (index != -1) {
            cout << "The element " << target << " is found at index " << index;
      }
      else {
            cout << "Element not found";
      }
}
