class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> window;
        int longest = 0, left = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            while (window.count(s[right])) {
                window.erase(s[left++]);
            }
            window.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};