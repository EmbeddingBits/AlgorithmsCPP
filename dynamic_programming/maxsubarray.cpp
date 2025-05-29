#include <iostream>
#include <algorithm>

int maxSubArray(int arr[], int size) {

    int max_so_far = arr[0];
    int current_max = arr[0];

    for (int i = 1; i < size; i++) {
        current_max = std::max(arr[i], current_max + arr[i]);
        max_so_far = std::max(max_so_far, current_max);
    }

    return max_so_far;
}

int main() {
    int arr[] = {12, 32, 45, 90, 87, 67, 65, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArray(arr, size);
    std::cout << max_sum;
    
    return 0;
}
