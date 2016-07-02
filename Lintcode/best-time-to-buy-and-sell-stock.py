class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def Solution(self):
        pass

    def maxProfit(self, prices):
        # write your code here
        n = len(prices)
        if n < 2: return 0
        dp = [0 for i in range(0, n+5)]
        ret = 0
        lo = prices[0]
        for i in range(1, n):
            ret = max(ret, prices[i]-lo)
            lo = min(lo, prices[i])
        return ret

s = Solution()
print s.maxProfit([3,2,3,1,2])