#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i = m + n - 1;
        int i1 = m - 1;
        int i2 = n - 1;

        while (i1 >= 0 && i2 >= 0) {
            if (num1[i1] >= num2[i2]) {
                num1[i] = num1[i1];
                i1--;
            }
            else {
                num1[i] = num2[i2];
                i2--;
            }
            i--;
        }

        while (i2 >= 0) {
            num1[i] = num2[i2];
            i2--;
            i--;
        }
    }
};

int main() {
    Solution* solution = new Solution();

    vector<int> num1;
    num1.push_back(1);
    num1.push_back(2);
    num1.push_back(3);
    num1.push_back(0);
    num1.push_back(0);
    num1.push_back(0);

    vector<int> num2;
    num2.push_back(2);
    num2.push_back(5);
    num2.push_back(6);

    solution->merge(num1, 3, num2, 3);

    cout << num1.size() << endl;
    for (int i = 0; i < num1.size(); i++) {
        cout << num1[i] << " ";
    }
    
}
