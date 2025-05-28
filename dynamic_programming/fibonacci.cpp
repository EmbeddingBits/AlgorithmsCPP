#include <iostream>
using namespace std;

int fibonacci(int n) {
      if (n == 0) {
            return 0;
      }

      int n1 = 0;
      int n2 = 1;

      for (int i = 0; i < n; i++) {
            int n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
      }

      return n2;
}

int main() {
      int n = 10;

      int ans = fibonacci(n);

      cout << ans;
}
