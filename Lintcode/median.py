class Solution:
    """
    @param nums: A list of integers.
    @return: An integer denotes the middle number of the array.
    """
    def median(self, nums):
        # write your code here
        nums = sorted(nums)
        a = []
        a.append(0)
        for i in range(0, len(nums)):
            a.append(nums[i])
        if len(nums) & 1:
            return a[(len(nums)>>1)+1]
        else:
            return a[len(nums)>>1]
