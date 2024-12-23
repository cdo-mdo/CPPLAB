#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    Solution* solution = new Solution();
    cout << solution->isAnagram(s, t) << endl;
    s = "car";
    t = "cat";
    cout << solution->isAnagram(s, t) << endl;
    delete solution;
}
