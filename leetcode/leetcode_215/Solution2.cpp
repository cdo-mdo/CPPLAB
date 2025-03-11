#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution2 {
public: 
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right]; // Pivot element (last element)
        int i = left;

        for (int j = left; j < right; j++) {
            if (nums[j] >= pivot) { // Sort in descending order
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    int quickselect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
    
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]); // Move pivot to end
    
        int partitionIndex = partition(nums, left, right);
    
        if (partitionIndex == k) {
            return nums[partitionIndex];
        } else if (partitionIndex < k) {
            return quickselect(nums, partitionIndex + 1, right, k);
        } else {
            return quickselect(nums, left, partitionIndex - 1, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    }
};

int main() {
    Solution2 sol;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << "Kth largest element: " << sol.findKthLargest(nums, k) << endl;
    return 0;
}