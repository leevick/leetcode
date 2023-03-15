#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &box, int truck) {
        sort(box.begin(), box.end(), [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; });
        int sum = 0, idx = 0;
        while (truck > 0) {
            if (truck >= box[idx][0]) {
                sum += box[idx][1] * box[idx][0];
                truck -= box[idx][0];
            } else {
                sum += truck * box[idx][1];
                truck = 0;
            }
            idx++;
        }
        return sum;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> prob = {{1, 3}, {5, 5}, {2, 5}, {4, 2}, {4, 1}, {3, 1}, {2, 2}, {1, 3}, {2, 5}, {3, 2}};
    cout << s.maximumUnits(prob, 35) << endl;
    return 0;
}
