#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        for (string str: strs) {
            string sortedString = str;
            sort(sortedString.begin(), sortedString.end());
            anagramGroups[sortedString].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& entry: anagramGroups) {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);

    for (const auto& group: result) {
        cout << "[";
        for (const auto& word: group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
