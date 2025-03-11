#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int slow = 0;
        int fast = 0;
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums.at(fast) != val) {
                nums.at(slow) = nums.at(fast);
                slow++;
            }
        }
        
        return slow;
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    Solution* solution = new Solution();
    solution->removeElement(nums, 3);

    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;
}
