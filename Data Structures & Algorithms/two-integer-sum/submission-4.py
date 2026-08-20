class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        difference = {}
        for i in range(len(nums)):
            if (target - nums[i]) in difference:
                return [difference[target - nums[i]],i]
            difference[nums[i]] = i        