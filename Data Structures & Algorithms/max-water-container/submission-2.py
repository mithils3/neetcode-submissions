class Solution:
    def maxArea(self, heights: List[int]) -> int:
        best = 0
        low, high = 0, len(heights) - 1
        while low < high:
            area = min(heights[low], heights[high]) * (high - low)
            best = max(best, area)
            if heights[low] < heights[high]:
                low += 1
            else:
                high -= 1
        return best