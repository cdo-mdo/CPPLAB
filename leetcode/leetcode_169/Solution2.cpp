#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0, count = 0;
        for (int num : nums)
        {
            if (count == 0)
                candidate = num;
            count += (num == candidate) ? 1 : -1;
            cout << "candidate = " << candidate << " count = " << count << endl;
        }
        return candidate;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 4, 5};
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
}
