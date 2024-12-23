#include <iostream>
#include <string>

using namespace std;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        const int NUMBER_OF_LOWER_CASE = 26;
        int arr[NUMBER_OF_LOWER_CASE];
        for (int i = 0; i < NUMBER_OF_LOWER_CASE; i++) {
            arr[i] = 0;
        }
        for (char c: s) {
            arr[c - 'a']++;
        }
        for (char c: t) {
            arr[c - 'a']--;
        }
        for (int i = 0; i < NUMBER_OF_LOWER_CASE; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }    
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    Solution1* solution = new Solution1();
    cout << solution->isAnagram(s, t) << endl;
    s = "car";
    t = "cat";
    cout << solution->isAnagram(s, t) << endl;

    delete solution;
}
