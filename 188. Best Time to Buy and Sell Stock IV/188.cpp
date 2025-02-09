#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int j = 1; j <= k; j++) {
            int max_diff = -prices[0];
            for (int i = 1; i < n; i++) {
                dp[i][j] = max(dp[i - 1][j], prices[i] + max_diff);
                max_diff = max(max_diff, dp[i][j - 1] - prices[i]);
            }
        }

        return dp[n - 1][k];
    }
};