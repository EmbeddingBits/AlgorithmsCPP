#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct numeral {
    int val;
    std::string sym;
};

const std::vector<numeral> nums = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
    {5, "V"}, {4, "IV"}, {1, "I"},
};

int romanToInt(std::string str) {
    if (str.empty()) {
        return 0;
    }

    int n = 0;
    for (const auto& i : nums) {
        while (str.rfind(i.sym, 0) == 0) {
            n += i.val;
            str = str.substr(i.sym.length());
        }
    }

    if (!str.empty()) {
        throw std::invalid_argument("Enter a valid roman numeral");
    }
    return n;
}

int main() {
    std::string str_val = "MDXLVI";
    try {
        int n = romanToInt(str_val);
        std::cout << n << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
