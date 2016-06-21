class Solution:
    """
    @param numbers : An array of Integer
    @param target : target = numbers[index1] + numbers[index2]
    @return : [index1 + 1, index2 + 1] (index1 < index2)
    """
    def Solution():
        pass
    def twoSum(self, numbers, target):
        # write your code here
        tmp = []
        for i in numbers:
            tmp.append(i)
        numbers = sorted(numbers)
        a = 0
        b = len(numbers) - 1
        while True:
            if numbers[a] + numbers[b] == target:
                break
            elif numbers[a] + numbers[b] < target:
                a += 1
            elif numbers[a] + numbers[b] > target:
                b -= 1
        reta = numbers[a]
        retb = numbers[b]
        a = -1
        b = -1
        for i in range(0, len(tmp)):
            if tmp[i] == reta and a == -1:
                a = i
            elif tmp[i] == retb and b == -1 and a != b:
                b = i
        if a > b:
            a = a ^ b
            b = a ^ b
            a = a ^ b
        return [a+1, b+1]
            
d = Solution()

print d.twoSum([0,4,3,0], 0)
