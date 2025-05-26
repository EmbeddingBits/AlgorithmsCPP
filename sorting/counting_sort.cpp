#include <iostream> 
#include <vector>   
#include <algorithm>

// countingSort sorts a vector of non-negative integers using the Counting Sort algorithm.
// It works by counting the occurrences of each element and then reconstructing the sorted vector.
// Time Complexity: O(N + K), where N is the number of elements in arr and K is the maximum value in arr.
void countingSort(std::vector<int>& arr) {
    // Handle empty vector case: no sorting needed.
    if (arr.empty()) {
        return;
    }

    // 1. Find the maximum element in the vector.
    // std::max_element returns an iterator to the largest element.
    // Dereference it (*) to get the actual value.
    int max = *std::max_element(arr.begin(), arr.end());

    // 2. Create a 'count' vector (or frequency vector) of size max + 1.
    // Initialize all elements to zero.
    std::vector<int> count(max + 1, 0);

    // 3. Populate the 'count' vector.
    // For each number in the input vector, increment its corresponding count.
    for (int num : arr) {
        count[num]++;
    }

    // 4. Reconstruct the sorted vector from the 'count' vector.
    // 'idx' tracks the current insertion position in the original 'arr'.
    int idx = 0;
    // 'val' iterates through possible numbers from 0 up to max.
    for (int val = 0; val <= max; ++val) {
        // Place 'val' into 'arr' as many times as it appeared in the input.
        while (count[val] > 0) {
            arr[idx] = val;
            idx++;           // Move to the next position in 'arr'
            count[val]--;    // Decrement the count for 'val'
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
