class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def Solution(self):
        pass
    def climbStairs(self, n):
        # write your code here
        fibo = []
        fibo.append(1)
        fibo.append(1)
        fibo.append(2)
        for i in range(3, 1000):
            fibo.append(fibo[i-1] + fibo[i-2])
        return fibo[n]
d = Solution()
print d.climbStairs(5)
