#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        // start from second last row and update each value to store the min path sum
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                // Add the minimum of the two possible path below
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0]; // Top level now contain the minimum path sum
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> triangle;
    triangle.push_back({2});
    triangle.push_back({3, 4});
    triangle.push_back({6, 5, 7});
    triangle.push_back({4, 1, 8, 3});

    cout << sol.minimumTotal(triangle) << endl;

    vector<vector<int>> triangle1;
    triangle1.push_back({-1});
    triangle1.push_back({2, 3});
    triangle1.push_back({1, -1, -3});
    cout << sol.minimumTotal(triangle1) << endl;
}
