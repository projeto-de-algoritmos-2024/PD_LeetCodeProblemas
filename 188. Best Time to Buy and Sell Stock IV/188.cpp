#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // Tabela dp para armazenar lucros máximos até o dia i com j transações
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int j = 1; j <= k; j++) {
            int max_diff = -prices[0]; // Armazena o lucro máximo de uma compra anterior
            for (int i = 1; i < n; i++) {
                // dp[i][j] pode ser o maior valor entre:
                // 1. Não fazer nada no dia i, mantendo o lucro do dia anterior (dp[i - 1][j])
                // 2. Vender a ação no dia i, onde o lucro seria: preço[i] + max_diff
                dp[i][j] = max(dp[i - 1][j], prices[i] + max_diff);
                max_diff = max(max_diff, dp[i][j - 1] - prices[i]);
            }
        }

        return dp[n - 1][k];
    }
};