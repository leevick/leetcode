#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int sum = 0, n = garbage.size();
        int gaps[3] = {0};
        int acc = 0;
        for (int i = 0; i < n; ++i) {
            acc += i > 0 ? travel[i - 1] : 0;
            sum += garbage[i].size();
            bool found[3] = {false};

            for (auto c : garbage[i]) {
                if (c == 'M') {
                    gaps[0] = acc;
                    found[0] = true;
                    continue;
                }
                if (c == 'G') {
                    gaps[1] = acc;
                    found[1] = true;
                    continue;
                }

                if (c == 'P') {
                    gaps[2] = acc;
                    found[2] = true;
                    continue;
                }

                if (found[0] && found[1] && found[2])
                    break;
            }
        }

        return sum + gaps[0] + gaps[1] + gaps[2];
    }
};