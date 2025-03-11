#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }    
};

int main() {
    Solution sol;

    cout << sol.trailingZeroes(3) << endl;
    cout << sol.trailingZeroes(5) << endl;
}