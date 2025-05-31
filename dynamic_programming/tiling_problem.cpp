#include <iostream>
#include <vector>

int tilingProblem(int n) {
      if (n <= 1) {
            return 1;
      }

      std::vector<int> dp(n+1);
      dp[0] = 1;
      dp[1] = 1;

      for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
      }

      return dp[n];
}

int main() {
      int n = 5;

      int ans = tilingProblem(n);

      std::cout << ans;
}
