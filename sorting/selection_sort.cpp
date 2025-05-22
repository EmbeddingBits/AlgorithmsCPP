#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {9, 8, 6, 7, 5, 4, 2, 3, 1, 0};
    int len = arr.size();

    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }

    for (int val : arr)
        std::cout << val << " ";

    return 0;
}

