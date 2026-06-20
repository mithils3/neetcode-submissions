#include <vector>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        int low = 0;
        int high = height * width - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            pair<int,int> coords = convert_xy(mid, height, width);
            int val = matrix[coords.second][coords.first];   // [row][col]
            if (val == target) return true;
            if (val > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
    pair<int, int> convert_xy(int num, int height, int width)
    {
        int x = num % width; // column
        int y = num / width; // row
        return {x, y};
    }
};