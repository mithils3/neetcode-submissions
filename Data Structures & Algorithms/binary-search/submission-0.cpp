class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int mid = nums.size() / 2;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
            mid = (high + low) / 2;
        }
        return -1;
    }
};
