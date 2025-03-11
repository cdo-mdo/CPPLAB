#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }    
};

int main() {
    Solution* solution = new Solution();

    vector<int> nums = {3, 2, 3};
    cout << solution->majorityElement(nums) << endl;
}