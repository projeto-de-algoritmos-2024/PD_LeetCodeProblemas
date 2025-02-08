from functools import lru_cache

class Solution:
    # Função recursiva
    def uniquePaths(self, m: int, n: int) -> int:
        @lru_cache(None)  
        def dp(i, j):
           
            if i == m - 1 and j == n - 1:
                return 1
            
            if i >= m or j >= n:
                return 0
            
            
            return dp(i + 1, j) + dp(i, j + 1)
        
        return dp(0, 0)  
    
    # Função iterativa
    def uniquePaths(self, m: int, n: int) -> int:
        
        dp = [[1] * n for _ in range(m)]
        
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        
        return dp[m - 1][n - 1] 
