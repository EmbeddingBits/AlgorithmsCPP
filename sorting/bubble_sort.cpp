#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {3, 4, 6, 2, 9, 1};
    int len = arr.size();

    for (int val : arr)
        std::cout << val << " ";
    std::cout << "\n";

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int val : arr)
        std::cout << val << " ";

    return 0;
}

