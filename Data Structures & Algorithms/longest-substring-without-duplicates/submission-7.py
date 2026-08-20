class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        state = set()
        best = 0
        l = 0
        for r in range(len(s)):
            while s[r] in state:      # shrink from left until duplicate removed
                state.remove(s[l])
                l += 1
            state.add(s[r])
            best = max(best, r - l + 1)
        return best