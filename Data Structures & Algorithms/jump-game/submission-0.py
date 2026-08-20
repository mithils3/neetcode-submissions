class Solution:
    def canJump(self, nums: List[int]) -> bool:
        self.jumpDP = {}
        self.jumpDP[len(nums)-1] = True
        self.nums = nums
        return self.recur(0)
    def recur(self,index):
        if index in self.jumpDP:
            return self.jumpDP[index]
        elif (index >= len(self.nums)):
            return False
        
        for i in range(1,self.nums[index]+1):
            if self.recur(index + i):
                self.jumpDP[index] = True
                return True
        self.jumpDP[index] = False
        return False