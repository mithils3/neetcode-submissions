class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1          # your jumpDP[n-1] = True, compressed to one int

        for index in range(len(nums) - 2, -1, -1):
            if index + nums[index] >= goal:   # replaces the entire inner for-loop
                goal = index                  # your jumpDP[index] = True

        return goal == 0                      # "can index 0 reach the end?"