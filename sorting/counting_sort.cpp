#include <iostream> 
#include <vector>   
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int max = *std::max_element(arr.begin(), arr.end());

    std::vector<int> count(max + 1, 0);

    for (int num : arr) {
        count[num]++;
    }

    int idx = 0;
    for (int val = 0; val <= max; ++val) {
        while (count[val] > 0) {
            arr[idx] = val;
            idx++;           
            count[val]--;    
        }
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1}; 

    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    std::cout << "Sorted array (Counting Sort): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
