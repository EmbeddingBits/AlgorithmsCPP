#include <iostream>

int abs(int n) {
      if (n < 0) {
            return -n;
      }
      return n;
}

int main (int argc, char *argv[]) {
      
      int n1 = 10;
      int n2 = -10;

      std::cout << abs(n1) << std::endl;
      std::cout << abs(n2) << std::endl;

      return 0;
}
