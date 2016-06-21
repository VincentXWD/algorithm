class Solution:
    """
    @param a, b, n: 32bit integers
    @return: An integer
    """
    def fastPower(self, a, b, n):
        # write your code here
        ret = 1
        while n:
            if n & 1:
                ret = (ret * a) % b
            n >>= 1
            a = (a * a) % b
        return ret % b
