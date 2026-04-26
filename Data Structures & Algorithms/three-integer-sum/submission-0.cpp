#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct threesum {
    int index1;
    int value1;
    int index2;
    int value2;
};

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        map<int, vector<threesum>> complement;
        set<vector<int>> seen;
        vector<vector<int>> output;

        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = i + 1; j < (int)nums.size(); ++j) {
                complement[nums[i] + nums[j]].push_back({i, nums[i], j, nums[j]});
            }
        }

        for (int i = 0; i < (int)nums.size(); ++i) {
            auto it = complement.find(-nums[i]);
            if (it == complement.end()) continue;

            for (threesum &p : it->second) {
                if (p.index1 == i || p.index2 == i) continue;   // can't reuse same index
                vector<int> triplet = {p.value1, p.value2, nums[i]};
                sort(triplet.begin(), triplet.end());           // canonical form
                if (seen.insert(triplet).second) {              // only push if new
                    output.push_back(triplet);
                }
            }
        }
        return output;
    }
};