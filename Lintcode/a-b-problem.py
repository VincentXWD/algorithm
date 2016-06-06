class Solution:
    """
    @param a: The first integer
    @param b: The second integer
    @return:  The sum of a and b
    """
    def aplusb(self, a, b):
        # write your code here, try to do it without arithmetic operators.
        if a == 0:
            return b
        if b == 0:
            return a
        x1 = a ^ b
        x2 = (a & b) << 1
        return aplusb(x1, x2)