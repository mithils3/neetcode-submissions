class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        AnagramsGroup = {}
        for i in strs:
            charCount = [0] * 26
            for c in i:
                charCount[ord(c) - ord('a')] += 1
            charCount = tuple(charCount)
            if charCount in AnagramsGroup:
                AnagramsGroup[charCount].append(i) 
            else:
                AnagramsGroup[charCount] = [i]
        output = []
        for key,value in AnagramsGroup.items():
            output.append(value)
        return output

