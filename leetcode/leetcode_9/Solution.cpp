#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool palindrome(int x) {
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }    
};

int main() {
    Solution sol;

    cout << sol.palindrome(121) << endl;
    cout << sol.palindrome(-121) << endl;

    cout << to_string(121) << endl;

    string s = to_string(123);
}
