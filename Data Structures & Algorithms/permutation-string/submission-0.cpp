class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        array<int, 26> FreqS1 = {};
        array<int, 26> FreqS2 = {};

        for (char c : s1)
        {
            FreqS1[c - 'a']++;
        }
        for (unsigned i = 0; i < s1.size(); i++)
        {
            FreqS2[s2[i] - 'a']++;
        }
        if (FreqS1 == FreqS2)
            return true;
        for (int i = s1.size(); i < s2.size(); i++)
        {
            FreqS2[s2[i] - 'a']++;
            FreqS2[s2[i - s1.size()] - 'a']--;
            if (FreqS1 == FreqS2)
                return true;
        }

        return false;
    }
};
