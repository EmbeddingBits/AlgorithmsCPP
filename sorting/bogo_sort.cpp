#include <iostream> 
#include <vector>   
#include <algorithm>
#include <random>   
#include <chrono>   

// isSorted checks if the given array is sorted in non-decreasing order.
// Time Complexity: O(N), where N is the number of elements in the vector.
bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// shuffle randomly shuffles the elements of the given vector using the Fisher-Yates algorithm.
// It iterates from the first element to the last, swapping each element with a randomly chosen element
// from the beginning of the vector up to and including the current element.
// Time Complexity: O(N), where N is the number of elements in the vector.
void shuffle(std::vector<int>& arr) {
    // Obtain a random number engine from the system clock
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed); 

    for (size_t i = 0; i < arr.size(); ++i) {
        // Create a uniform distribution for integers between 0 and i (inclusive)
        std::uniform_int_distribution<size_t> dist(0, i);
        size_t j = dist(rng); // Generate a random index 'j'

        std::swap(arr[i], arr[j]); // Swap elements at 'i' and 'j'
    }
}

// bogoSort sorts the given vector using the Bogo Sort algorithm.
// It repeatedly shuffles the vector until it becomes sorted. This is highly inefficient.
// Time Complexity: Average O(N!), Worst Case O(infinity)
std::vector<int> bogoSort(std::vector<int>& arr) {
    while (!isSorted(arr)) {
        shuffle(arr);
    }
    return arr;
}

int main() {
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    bogoSort(arr);

    std::cout << "Sorted array (Bogo Sort): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0; // Indicate successful execution
}
