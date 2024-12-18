#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int i;
        for (i = 0; i < nums.size(); i++) {
            int min = INT_MAX;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i] && nums[j] < min) {
                    min = nums[j];
                }
            }
            if (min == INT_MAX) {
                break;
            }
            nums[i + 1] = min;
        }
        return i + 1;
    }    
};

int main(int argc, char** argv) {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6};
    Solution* solution = new Solution();

    cout << solution->removeDuplicates(nums) << endl;
}