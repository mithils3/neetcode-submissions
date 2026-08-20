class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # build the first array
        if (len(s1) > len(s2)):
             return False
        charCounterS1 = [0]*26
        charCounterS2 = [0]*26

        for i in s1:
            charCounterS1[ord(i) - ord('a')] += 1
        for i in range(len(s2)):
            if (charCounterS1 == charCounterS2):
                return True
            if (i >= len(s1)):
                charCounterS2[ord(s2[i-len(s1)]) - ord('a')] -= 1
            charCounterS2[ord(s2[i]) - ord('a')] += 1
        if (charCounterS1 == charCounterS2):
                return True
        return False

