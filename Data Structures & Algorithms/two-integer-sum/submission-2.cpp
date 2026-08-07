#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> sum;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum.find(nums[i]) != sum.end())
            {
                return {sum[nums[i]], i};
            }
            sum.insert({target - nums[i], i});
        }
        return {0,0};
    }
};
