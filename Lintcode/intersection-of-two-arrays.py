class Solution:
    # @param {int[]} nums1 an integer array
    # @param {int[]} nums2 an integer array
    # @return {int[]} an integer array
    def Solution(self):
        pass
    def intersection(self, nums1, nums2):
        # Write your code here
        nums3 = []
        n1 = len(nums1)
        n2 = len(nums2)
        if n1 == 0 or n2 == 0:
            return nums3
        nums1.sort(), nums2.sort()
        j = 0
        for i in range(0, n1):
            while 1:
                if j >= n2:
                    break
                if nums2[j] < nums1[i]:
                    j += 1
                elif nums2[j] == nums1[i]:
                    nums3.append(nums1[i])
                    j += 1
                    break
                elif nums2[j] > nums1[i]:
                    break
        n3 = len(nums3)
        nums4 = []
        nums4.append(nums3[0])
        for i in range(1, n3):
            if nums3[i] == nums3[i-1]:
                continue
            nums4.append(nums3[i])
        return nums4