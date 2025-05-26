#include <iostream> 
#include <vector>   
#include <algorithm>

// merge combines two sorted integer vectors (left and right) into a single sorted vector.
// It iterates through both vectors, comparing elements and appending the smaller one to the result.
// It then appends any remaining elements from either vector.
// Time Complexity: O(N + M), where N is left.size() and M is right.size().
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    // Create a new vector to store the merged result.
    // Reserve capacity to avoid frequent reallocations.
    std::vector<int> result;
    result.reserve(left.size() + right.size());

    size_t i = 0; // Index for the left vector
    size_t j = 0; // Index for the right vector

    // Iterate while both vectors have elements to compare.
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) { // Use <= for stability (if equal, take from left first)
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

// mergeSort sorts a vector of integers using the Merge Sort algorithm.
// It's a recursive, "divide and conquer" algorithm.
// Time Complexity: O(N log N)
std::vector<int> mergeSort(std::vector<int> arr) { // arr is passed by value to allow slicing
    // Base case: If the vector has 0 or 1 element, it's already sorted.
    if (arr.size() <= 1) {
        return arr;
    }

    // 1. Divide: Find the middle point to split the vector into two halves.
    size_t mid = arr.size() / 2;

    // Create left and right sub-vectors.
    // In C++, creating sub-vectors typically involves iterators or copying.
    // std::vector<int> left(arr.begin(), arr.begin() + mid);
    // std::vector<int> right(arr.begin() + mid, arr.end());
    // Or more succinctly using range constructor:
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


    // 2. Conquer: Recursively sort both halves.
    left = mergeSort(left);
    right = mergeSort(right);

    // 3. Combine: Merge the two sorted halves back into a single sorted vector.
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
