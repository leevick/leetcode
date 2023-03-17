#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        long long ret = 0;
        long long hash[26] = {0};

        for (int i = 0; i < n; ++i) {
            ret += hash[s[i] - 'a'];
            hash[s[i] - 'a']++;
        }

        return ret + n;
    }
};