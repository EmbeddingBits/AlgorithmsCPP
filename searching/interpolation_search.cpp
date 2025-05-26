#include <iostream> 
#include <vector>   
using namespace std;

// Function to perform interpolation search
int interpolationSearch(const std::vector<int>& arr, int low, int high, int x) {
    // Base case: Check if the search space is valid and if x is within the range of values
    if (low <= high && x >= arr[low] && x <= arr[high]) {
        // Handle the case where arr[high] == arr[low] to prevent division by zero
        // If they are equal, then x must also be equal to this value for a match
        if (arr[high] == arr[low]) {
            return (arr[low] == x) ? low : -1;
        }

        // Calculate the probe position
        // Note: C++ integer division naturally truncates, which is desired here.
        long long pos = low + ((static_cast<long long>(high - low) * (x - arr[low])) / (arr[high] - arr[low]));

        // Check if the element at 'pos' is the target
        if (arr[pos] == x) {
            return pos; // Element found
        }

        // If the element at 'pos' is less than x, search in the right sub-array
        if (arr[pos] < x) {
            return interpolationSearch(arr, pos + 1, high, x);
        }
        // If the element at 'pos' is greater than x, search in the left sub-array
        else { // arr[pos] > x
            return interpolationSearch(arr, low, pos - 1, x);
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {2, 5, 7, 8, 11, 12, 15, 18, 20, 22};
    int x = 12;
    int n = arr.size();

    int index = interpolationSearch(arr, 0, n - 1, x);

    if (index != -1) {
        cout << "Element " << x << " found at index " << index << std::endl;
    } else {
        cout << "Element " << x << " not found in the array" << std::endl;
    }
    return 0;
}
