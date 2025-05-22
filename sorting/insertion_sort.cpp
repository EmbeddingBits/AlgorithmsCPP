#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {7, 6, 4, 1, 3, 2, 5, 9, 0, 8};
    int len = arr.size();

    for (int val : arr)
        std::cout << val << " ";
    std::cout << "\n";

    for (int i = 0; i < len; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    for (int val : arr)
        std::cout << val << " ";

    return 0;
}

