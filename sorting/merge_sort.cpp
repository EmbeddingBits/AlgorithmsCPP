#include <iostream> 
#include <vector>   

// Time Complexity: O(N + M), where N is left.size() and M is right.size().
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    result.reserve(left.size() + right.size());

    size_t i = 0; // Index for the left vector
    size_t j = 0; // Index for the right vector

    // Iterate while both vectors have elements to compare.
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) { 
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // Append any remaining elements from the left vector (if any).
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    // Append any remaining elements from the right vector (if any).
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    return result;
}

// Time Complexity: O(N log N)
std::vector<int> mergeSort(std::vector<int> arr) {
    if (arr.size() <= 1) { // Base Case
        return arr;
    }

    // 1. Divide
    size_t mid = arr.size() / 2;

    std::vector<int> left;
    left.reserve(mid); // Pre-allocate for efficiency
    for (size_t k = 0; k < mid; ++k) {
        left.push_back(arr[k]);
    }

    std::vector<int> right;
    right.reserve(arr.size() - mid); // Pre-allocate for efficiency
    for (size_t k = mid; k < arr.size(); ++k) {
        right.push_back(arr[k]);
    }


    // 2. Conquer:
    left = mergeSort(left);
    right = mergeSort(right);

    // 3. Combine
    return merge(left, right);
}

int main() {
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::vector<int> sorted = mergeSort(arr);

    std::cout << "Sorted array (Merge Sort): ";
    for (int x : sorted) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0; 
}
