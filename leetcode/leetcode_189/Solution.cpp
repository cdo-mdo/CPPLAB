#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        // reverse the array
        reverse(nums, 0, nums.size() - 1);

        // reverse first k element
        reverse(nums, 0, k - 1);

        // reverse remaining element from k
        reverse(nums, k, nums.size() - 1);
    }
    
    void reverse(vector<int>& nums, int start, int end) {
        int i = start;
        int j = end;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    sol.rotate(nums, 3);
    for (int num: nums) {
        cout << num << " ";
    }
}