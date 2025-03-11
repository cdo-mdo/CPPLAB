#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> memo;
    int m;
    int n;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        memo = vector<vector<int>>(m, vector<int>(n, -1));

        return dp (obstacleGrid, 0, 0);
    }

    int dp(vector<vector<int>> &grid, int i, int j) {
        if (i >= m || j >= n) {
            return 0;
        }

        if (grid[i][j] == 1) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        return memo[i][j] = dp(grid, i, j + 1) + dp(grid, i + 1, j);
    }
};
