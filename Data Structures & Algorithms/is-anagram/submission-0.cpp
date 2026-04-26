#include <string>
#include <array>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        std::array<int, 26> sMap = {0};
        std::array<int, 26> tMap = {0};
        for (char i : s)
        {
            sMap[i - 'a']++;
        }
        for (char i : t)
        {
            tMap[i - 'a']++;
        }
        return tMap == sMap;
    }
};
