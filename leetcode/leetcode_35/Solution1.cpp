#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }    
};

int main() {
    Solution1 sol1;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    cout << "Insert position: " << sol1.searchInsert(nums, target) << endl;
    return 0;
}