class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (int i : s) {
            if (!s.contains(i - 1)) {
                int num = i + 1;
                int tmp = 1;
                while (s.contains(num)) {
                    tmp++;
                    num++;
                }
                longest = max(longest, tmp);
            }
        }
        return longest;
    }
};