
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dp(int start, int end, vector<int> &vec)
    {

        int ret = 0;
        if (start == end)
        {
            return 0;
        }
        else if (start > end)
        {
            return 0;
        }
        else
        {

            if (end - start < 2)
            {
                return 0;
            }
            else
            {
                int level = min(vec[start], vec[end]);
                for (int i = start + 1; i < end; i++)
                {
                    ret += (level - vec[i]);
                }
            }
        }

        return ret;
    }

    int trap(vector<int> &height)
    {

        vector<int> indexes;
        for (auto i = 0; i < height.size(); i++)
        {
            indexes.push_back(i);
        }

        stable_sort(indexes.begin(), indexes.end(), [&height](int a, int b)
                    { return height[a] > height[b]; });

        

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    s->trap(a);
    return 0;
}
