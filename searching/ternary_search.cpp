#include <iostream> 
#include <iomanip>

// Uni-modal function
// Time Complexity: O(1)
double f(double x) {
    return -(x - 3) * (x - 3) + 9;
}

// Ternary search function
// Time Complexity: O(log N)
double ternarySearch(double left, double right, double eps) {
    // Loop continues until the interval (right - left) is smaller than eps
    while (right - left > eps) {
        // Calculate the two probe points
        double m1 = left + (right - left) / 3;
        double m2 = right - (right - left) / 3;

        // Compare function values at m1 and m2
        // If f(m1) < f(m2), the maximum must be to the right of m1
        if (f(m1) < f(m2)) {
            left = m1; // Adjust the left boundary
        } else {
            // Otherwise, the maximum must be to the left of m2 (or at m2)
            right = m2; // Adjust the right boundary
        }
    }
    // Return the midpoint of the final, small interval as the approximate extremum
    return (left + right) / 2;
}

int main() {
    double left = 0.0; // Left boundary of the search interval
    double right = 6.0; // Right boundary of the search interval
    double eps = 1e-7; // Epsilon, the desired precision

    // Perform the ternary search
    double x = ternarySearch(left, right, eps);

    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Maximum at x ~ " << x << ", f(x) ~ " << f(x) << std::endl;

    return 0; 
}
