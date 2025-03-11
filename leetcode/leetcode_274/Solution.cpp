#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int i;
        for (i = 0; i < citations.size(); i++) {
            if (i + 1 > citations[i]) {
                break;
            }
        }
        return i;
    }    
};

int main() {
    Solution sol;
    vector<int> citations = {3, 0, 6, 1, 5};
    vector<int> citations1 = {1, 3, 1};

    cout << sol.hIndex(citations) << endl;
    cout << sol.hIndex(citations1) << endl;
}