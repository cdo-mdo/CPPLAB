#inlcude <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n + 1, 0);

        // Count how many paper have each number of citations
        for (int c : citations) {
            if (c >= n) {
                bucket[n]++; // count paper with citation >= n
            }
            else {
                bucket[c]++;
            }
        }

        int h = 0;
        for (int i = n; i >= 0; i--) {
            h += bucket[i];
            if (h >= i) {
                return i;
            }
        }
        return 0;
    }    
};