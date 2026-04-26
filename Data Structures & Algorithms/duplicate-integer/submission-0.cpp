#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        std::set<int> sample;
        for (int i : nums)
        {
            if (sample.contains(i))
                return true;
            sample.insert(i);
        }
        return false;
    }
};