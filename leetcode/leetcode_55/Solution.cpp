#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1) {
            return true;
        }

        int maxLength = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxLength = max(maxLength, nums[i] + i);
            if (maxLength < i + 1) {
                return false;
            }
            if (maxLength >= nums.size() - 1)
            {   
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 3, 1, 1, 4};
    cout << sol.canJump(nums) << endl;

    nums = {3, 2, 1, 0, 4};
    cout << sol.canJump(nums) << endl;
}
