#include <iostream>
#include <vector>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int majorityCount = nums.size() / 2;

        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > majorityCount) {
                return num;
            }
        }

        return -1;
    }    
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
}