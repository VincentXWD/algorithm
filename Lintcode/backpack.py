class Solution:
    # @param m: An integer m denotes the size of a backpack
    # @param A: Given n items with size A[i]
    # @return: The maximum size
    def Solution(self):
        pass
    def backPack(self, m, A):
        # write your code here
        dp = [0 for i in range(0, 100000)]
        for i in range(0, len(A)):
            for j in range(m, A[i]-1, -1):
                dp[j] = max(dp[j], dp[j-A[i]]+A[i])
        return dp[m]
d = Solution()

print d.backPack(11, [2, 3, 5, 7])
