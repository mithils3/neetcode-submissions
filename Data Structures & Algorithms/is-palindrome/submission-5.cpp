#include <string>
#include <cctype>

using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        size_t i = 0;
        size_t j = s.size() - 1;
        while (i < j)
        {
            if (!std::isalnum(static_cast<unsigned char>(s[i])))
            {
                ++i;
                continue;
            }
            if (!std::isalnum(static_cast<unsigned char>(s[j])))
            {
                --j;
                continue;
            }
            if (tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[j])))
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
