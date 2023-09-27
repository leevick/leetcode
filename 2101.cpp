#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        const int n = bombs.size();
        auto mdet = vector<int>(n, 1);
        auto adj = vector<vector<int>>(n, vector<int>(n, 0));

        // calculate adjacency
        for (auto i = 0; i < n - 1; ++i) {
            auto x1 = bombs[i][0];
            auto y1 = bombs[i][1];
            auto r1 = bombs[i][2];

            for (auto j = i + 1; j < n; ++j) {
                auto x2 = bombs[j][0];
                auto y2 = bombs[j][1];
                auto r2 = bombs[j][2];

                auto diff = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if (diff <= r1 * r1) {
                    adj[i][j] = 1;
                }

                if (diff <= r2 * r2) {
                    adj[j][i] = 1;
                }
            }
        }

        auto needCalc = vector<bool>(n, true);

        for (auto i = 0; i < n; ++i) {
            if (needCalc[i]) {
                auto visited = vector<bool>(n, false);
                list<int> q;
                q.push_back(i);
                visited[i] = true;

                while (!q.empty()) {
                    int cur = q.front();
                    q.pop_front();

                    for (auto j = 0; j < n; ++j) {
                        if (adj[i][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            needCalc[j] = false;
                            mdet[i]++;
                            q.push_back(j);
                        }
                    }
                }
            }
        }

        return *max_element(mdet.begin(), mdet.end());
    }
};

int main(int argc, char const *argv[]) {

    Solution s;
    vector<vector<int>> t1 = {{2, 1, 3}, {6, 1, 4}};
    vector<vector<int>> t2 = {{1, 1, 5}, {10, 10, 5}};
    vector<vector<int>> t3 = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};

    cout << s.maximumDetonation(t1) << endl;
    cout << s.maximumDetonation(t2) << endl;
    cout << s.maximumDetonation(t3) << endl;
    return 0;
}
