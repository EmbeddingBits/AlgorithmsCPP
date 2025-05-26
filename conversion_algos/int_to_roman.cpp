#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

const std::vector<std::string> r0 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const std::vector<std::string> r1 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const std::vector<std::string> r2 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const std::vector<std::string> r3 = {"", "M", "MM", "MMM"};

std::string intToRoman(int n) {
    if (n < 1 || n > 3999) {
        throw std::out_of_range("Number must be between 1 to 3999");
    }
    return r3[n / 1000] + r2[(n % 1000) / 100] + r1[(n % 100) / 10] + r0[n % 10];
}

int main() {
    int n_val = 1546;
    try {
        std::string roman = intToRoman(n_val);
        std::cout << roman << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    n_val = 4000;
    try {
        std::string roman = intToRoman(n_val);
        std::cout << roman << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
