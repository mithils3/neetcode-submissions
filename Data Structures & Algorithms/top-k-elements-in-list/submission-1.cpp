#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqmap;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> output;

        for (int x : nums)
        {
            freqmap[x]++;
        }

        for (auto [num, freq] : freqmap)
        {
            buckets[freq].push_back(num);
        }

        for (int i = (int)buckets.size() - 1; i >= 0 && output.size() < k; --i)
        {
            for (int num : buckets[i])
            {
                output.push_back(num);
                if (output.size() == k)
                {
                    return output;
                }
            }
        }

        return output;
    }
};