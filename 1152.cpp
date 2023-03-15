#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

class Solution
{
public:
    vector<string> mostVisitedPattern(vector<string> &user,
                                      vector<int> &time,
                                      vector<string> &site) {

        int n = user.size();
        vector<int> idx(n, 0);

        struct info
        {
            int i;
            int j;
            int k;
            mutable int count;
            mutable set<string> users;
        };
        map<tuple<string, string, string>, info> hash;
        iota(idx.begin(), idx.end(), 0);

        // Sort Time O(log(n))
        stable_sort(idx.begin(), idx.end(), [&time](int a, int b) { return time[a] < time[b]; });
        /*
        for (auto st : idx) {
            cout << time[st] << " ";
        }
        cout << endl;

        for (auto st : idx) {
            cout << user[st] << "\t\t->\t\t" << site[st] << " " << endl;
        }
        cout << endl;
        */

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (user[idx[i]] != user[idx[j]]) {
                    continue;
                }
                for (int k = j + 1; k < n; ++k) {
                    if (user[idx[j]] != user[idx[k]]) {
                        continue;
                    }

                    auto it = hash.find(make_tuple(site[idx[i]], site[idx[j]], site[idx[k]]));
                    if (it == hash.end()) {
                        hash[make_tuple(site[idx[i]], site[idx[j]], site[idx[k]])] = {i, j, k, 1, {user[idx[i]]}};
                    } else {
                        if (it->second.users.find(user[idx[i]]) == it->second.users.end()) {
                            it->second.count++;
                            it->second.users.insert(user[idx[i]]);
                        }
                    }
                    // cout << "user = " << user[idx[i]] << " " << site[idx[i]] << " " << site[idx[j]] << " " << site[idx[k]] << " count = " << hash[site[idx[i]] + site[idx[j]] + site[idx[k]]].count << endl;
                }
            }
        }

        auto comp = [&idx, &site](const info &a,
                                  const info &b) { return a.count < b.count ? true : a.count == b.count ? (site[idx[a.i]] + site[idx[a.j]] + site[idx[a.k]]) >= (site[idx[b.i]] + site[idx[b.j]] + site[idx[b.k]])
                                                                                                        : false; };

        priority_queue<info, vector<info>, decltype(comp)> pq(comp);

        for (auto it : hash) {

            cout << get<0>(it.first) << "," << get<1>(it.first) << "," << get<2>(it.first) << " -> " << it.second.count << endl;
            pq.push(it.second);
        }

        return {site[idx[pq.top().i]], site[idx[pq.top().j]], site[idx[pq.top().k]]};
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> user = {"him", "mxcmo", "jejuvvtye", "wphmqzn", "uwlblbrkqv", "flntc", "esdtyvfs", "nig", "jejuvvtye", "nig", "mxcmo", "flntc", "nig", "jejuvvtye", "odmspeq", "jiufvjy", "esdtyvfs", "mfieoxff", "nig", "flntc", "mxcmo", "qxbrmo"};
    vector<int> time = {113355592, 304993712, 80831183, 751306572, 34485202, 414560488, 667775008, 951168362, 794457022, 813255204, 922111713, 127547164, 906590066, 685654550, 430221607, 699844334, 358754380, 301537469, 561750506, 612256123, 396990840, 60109482};
    vector<string> web = {"k", "o", "o", "nxpvmh", "dssdnkv", "kiuorlwdcw", "twwginujc", "evenodb", "qqlw", "mhpzoaiw", "jukowcnnaz", "m", "ep", "qn", "wxeffbcy", "ggwzd", "tawp", "gxm", "pop", "xipfkhac", "weiujzjcy", "x"};

    auto ret = s.mostVisitedPattern(user, time, web);

    for (auto i : ret) {
        cout << i << endl;
    }

    return 0;
}
