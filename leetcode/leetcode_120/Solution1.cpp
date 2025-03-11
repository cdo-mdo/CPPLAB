#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> memo;

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memo.assign(n, vector<int>(n, INT_MAX)); // Inittilize memo table
        return dp(triangle, 0, 0);
    }

    int dp(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        if (memo[i][j] != INT_MAX) {
            return memo[i][j];
        }

        return memo[i][j] = triangle[i][j] + min(dp(triangle, i + 1, j), dp(triangle, i + 1, j + 1));
    }

};