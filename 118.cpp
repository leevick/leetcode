#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows) {
        auto ret = vector<vector<int>>();
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                ret.push_back(vector<int>(1, 1));
            } else if (i == 1) {
                ret.push_back(vector<int>(2, 1));
            } else {
                auto r = vector<int>();
                for (int j = 0; j <= i; j++) {
                    if (j == 0) {
                        r.push_back(1);
                    } else if (j == i) {
                        r.push_back(1);
                    } else {
                        r.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
                    }
                }
                ret.push_back(r);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    auto sol = new Solution();
    auto ret = sol->generate(3);
    for (auto m : ret) {
        for (auto n : m) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
