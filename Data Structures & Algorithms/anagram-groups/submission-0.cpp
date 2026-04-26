#include <vector>
#include <string>
#include <map>
#include <array>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> output;
        map<array<int, 26>, vector<string>> count;
        for (string i : strs)
        {
            array<int, 26> charCount = {0};
            for (char j : i)
            {
                charCount[j - 'a']++;
            }
            count[charCount].push_back(i);
        }
        for (auto &[k, v] : count)
        {
            output.push_back(v);
        }
        return output;
    }
};
