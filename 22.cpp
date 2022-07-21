#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    void rec(string curr, int sum, int left, int right, vector<string> &ret)
    {
        if (left == 0 && right == 0 && sum == 0)
        {
            ret.push_back(curr);
        }
        else
        {
            // add left
            if (left > 0)
            {
                rec(curr + "(", sum + 1, left - 1, right, ret);
            }

            // add right
            if (right > 0 && sum - 1 >= 0)
            {
                rec(curr + ")", sum - 1, left, right - 1, ret);
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        auto ret = vector<string>();
        rec("", 0, n, n, ret);
        return ret;
    }
};

int main(int argc, char const *argv[])
{

    auto sol = new Solution();
    auto ret = sol->generateParenthesis(atoi(argv[1]));
    for (auto s : ret)
    {
        cout << s << endl;
    }
    return 0;
}
