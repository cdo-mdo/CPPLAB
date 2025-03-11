#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

int main() {
    Solution1 sol1;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << sol1.findKthLargest(nums, 4) << endl;
}
