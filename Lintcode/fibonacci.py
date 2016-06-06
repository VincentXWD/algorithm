class Solution:
    # @param n: an integer
    # @return an integer f(n)
    def fibonacci(self, n):
        # write your code here
        dp = []
        for i in range(0, 1000):
            dp.append(0)
        dp[0] = 0
        dp[1] = 0
        dp[2] = 1
        for i in range(3, 1000):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]