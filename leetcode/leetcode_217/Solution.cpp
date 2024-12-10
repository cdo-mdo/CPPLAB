#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seens;
        for (int num: nums) {
            if (seens.count(num)) {
                return true;
            }
            seens.insert(num);
        }
        return false;
    }    
};

int main(int argc, char** argv) {
    Solution* solution = new Solution();

    vector<int> nums = {1, 2, 3, 3};

    cout << "hello" << endl;

    cout << solution->hasDuplicate(nums) << endl;

}
