#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        for (int price: prices) {
            if (minPrice > price) {
                minPrice = price;
            }
            else {
                if (profit < price - minPrice) {
                    profit = price - minPrice;
                }

            }
        }
        return profit;
    }
};

int main() {
    Solution* solution = new Solution();

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << solution->maxProfit(prices) << endl;

    delete solution;
}
