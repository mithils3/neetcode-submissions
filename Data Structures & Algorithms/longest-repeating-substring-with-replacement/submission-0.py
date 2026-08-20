class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        best = 0
        l = 0
        maxFreq = 0
        for r in range(len(s)):
            count[s[r]] = count.get(s[r], 0) + 1
            maxFreq = max(maxFreq, count[s[r]])
            # chars to replace = window size - most common char count
            if (r - l + 1) - maxFreq > k:
                count[s[l]] -= 1
                l += 1
            best = max(best, r - l + 1)
        return best