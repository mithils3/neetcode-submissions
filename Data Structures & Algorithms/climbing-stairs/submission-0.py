class Solution:
    def climbStairs(self, n: int) -> int:
        prev = {1:1,2:2}
        if n == 1:
            return 1
        if n == 2:
            return 2
        for i in range(3,n+1):
            prev[i] = prev[i-1] + prev[i - 2]
        return prev[n]