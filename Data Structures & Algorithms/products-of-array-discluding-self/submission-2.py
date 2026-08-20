class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = []
        for i in range(n):
            if i == 0:
                prefix.append(1)
            else:
                prefix.append(nums[i-1] * prefix[i-1])

        suffix = [1] * n
        for i in range(n - 2, -1, -1):
            suffix[i] = nums[i+1] * suffix[i+1]

        return [prefix[i] * suffix[i] for i in range(n)]