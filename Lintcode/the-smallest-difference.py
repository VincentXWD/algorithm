class Solution:
    # @param A, B: Two lists of integer
    # @return: An integer
    def Solution():
        pass
    def smallestDifference(self, A, B):
        # write your code here
        A.sort()
        B.sort()
        i = 0
        j = 0
        ret = 2147483647
        while i < len(A) and j < len(B):
            ret = min(ret, abs(A[i]-B[j]))
            if A[i] > B[j]:
                j += 1
            elif A[i] < B[j]:
                i += 1
            elif A[i] == B[j]:
                ret = 0
                break
        return ret

a = Solution()

print a.smallestDifference([3,4,6,7], [2,3,8,9])
