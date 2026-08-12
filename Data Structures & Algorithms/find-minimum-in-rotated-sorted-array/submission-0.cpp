#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = -1;
        int hi = nums.size();
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2 ;
            if (nums[mid] <= nums[nums.size()-1]) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
    return nums[hi];
    }
};
