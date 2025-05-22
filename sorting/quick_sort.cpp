#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[++i], arr[end]);
    return i;
}

void quickSort(std::vector<int>& arr, int start, int end) {
    if (start >= end) return;
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int main() {
    std::vector<int> arr = {4, 3, 1, 2, 5, 6, 0, 8, 7, 9};
    quickSort(arr, 0, arr.size() - 1);

    for (int val : arr)
        std::cout << val << " ";

    return 0;
}

