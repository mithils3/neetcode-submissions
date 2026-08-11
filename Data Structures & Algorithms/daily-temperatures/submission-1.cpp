#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<std::pair<int, int>> s;
        vector<int> output;
        output.resize(temperatures.size());
        for (unsigned int x = 0; x < temperatures.size(); x++)
        {
            while (!s.empty() && s.top().second < temperatures[x])
            {
                auto popped = s.top();
                s.pop();
                output[popped.first] = x - popped.first;
            }
            s.push({x,temperatures[x]});
        }
        return output;
    }
};
// for this we want Next Greater Temperature to the right