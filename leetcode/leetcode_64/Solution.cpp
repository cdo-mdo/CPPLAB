#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> memo;

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(grid, 0, 0);
    }

    int dp(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n)
        {
            return INT_MAX;
        }
        if (i == m - 1 && j == n - 1)
        {
            return grid[i][j];
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        return memo[i][j] = grid[i][j] + min(dp(grid, i, j + 1), dp(grid, i + 1, j));
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    cout << sol.minPathSum(grid) << endl;
}