#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        map<char, int> maps;
        for (char c: s) {
            if (maps.find(c) == maps.end()) {
                maps[c] = 1;
            }
            else {
                maps[c]++;
            }
        }
        for (char c: t) {
            if (maps.find(c) == maps.end()) {
                return false;
            }
            else {
                maps[c]--;
            }
        }
        map<char, int>::iterator it = maps.begin();
        while (it != maps.end()) {
            if (it -> second != 0) {
                return false;
            }
            ++it;
        }
        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    Solution2* solution = new Solution2();
    cout << solution->isAnagram(s, t) << endl;
    s = "car";
    t = "cat";
    cout << solution->isAnagram(s, t) << endl;

    delete solution;
}
