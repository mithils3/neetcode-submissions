class Solution:
    def robR(self,houseI : int):
        if (houseI >= len(self.nums)):
            return 0
        if houseI in self.prevInfo:
            return self.prevInfo[houseI]
        self.prevInfo[houseI] = max(self.robR(houseI+1),self.robR(houseI+2) + self.nums[houseI])
        return self.prevInfo[houseI]
    def rob(self, nums: List[int]) -> int:
        self.prevInfo = {}
        self.nums = nums
        return self.robR(0)

    
