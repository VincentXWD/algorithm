class Solution:
	"""
	@param numbersbers : Give an array numbersbers of n integer
	@return : Find all unique triplets in the array which gives the sum of zero.
	"""
	def Solution(self):
		pass
	def threeSum(self, numbers):
		# write your code here
		numbers.sort()
		ret = []
		n = len(numbers)
		for i in range(0, n):
			for j in range(i+1, n):
				d = -(numbers[j] + numbers[i])
				l = 0
				r = n - 1
				p = -1
				while l <= r:
					m = (l + r) >> 1
					if numbers[m] == d:
						p = m
						break
					elif numbers[m] > d:
						r = m - 1
					elif numbers[m] < d:
						l = m + 1
				if p != -1 and p != i and p != j:
					ret.append((numbers[i], numbers[j], numbers[p]))
		nn = len(ret)
		for i in range(0, nn):
			ret[i] = list(ret[i])
			ret[i].sort()
			ret[i] = tuple(ret[i])
		ret = list(set(ret))
		return ret
