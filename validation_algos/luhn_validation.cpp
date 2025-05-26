/* 
(From right) → 7, 6, 4, 6, 3, 4, 3, 0, 8, 8, 4, 1, 9, 3, 5, 4
Double these:    ↑   ↑   ↑   ↑   ↑   ↑   ↑   ↑
Becomes:         7, 12, 4, 12, 3, 8, 3, 0, 8, 16, 4, 2, 9, 6, 5, 8
Then subtract 9 from values > 9:
                 7, 3, 4, 3, 3, 8, 3, 0, 8, 7, 4, 2, 9, 6, 5, 8
Sum: **70**
→ `70 % 10 == 0` → Valid 
*/

#include <iostream>
#include <string>
#include <cctype>

bool luhnCheck(const std::string& number) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = number.size() - 1; i >= 0; --i) {
        if (!isdigit(number[i])) continue;

        int digit = number[i] - '0';
        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }
    return sum % 10 == 0;
}

int main() {
    std::string number = "4539148803436467";
    if (luhnCheck(number)) {
        std::cout << "Valid Luhn Number\n";
    } else {
        std::cout << "Invalid Luhn Number\n";
    }
    return 0;
}

