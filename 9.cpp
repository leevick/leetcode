#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x) {
        char buffer[256] = {0};
        sprintf(buffer, "%d", x);
        string s(buffer);
        const int N = s.size();
        int i = 0;
        while (i < N - 1 - i) {
            if (s[i] != s[N - 1 - i])
                return false;
            i++;
        }
        return true;
    }
};