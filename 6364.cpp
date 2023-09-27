#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    struct cheese {
      int value;
      int mouse;
      int m1;
      int m2;
      bool operator<(const cheese& c) { return this->value > c.value; }
    };

    int ret = 0, n = reward1.size();
    vector<cheese> c;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
      cheese ch;
      ch.value = reward1[i] - reward2[i];
      ch.m1 = reward1[i];
      ch.m2 = reward2[i];
      c.push_back(ch);
    }

    sort(c.begin(), c.end());

    for (int i = 0; i < k; ++i) {
      ret += c[i].m1;
    }

    for (int i = k; i < n; ++i) {
      ret += c[i].m2;
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> rw11 = {1, 1, 3, 4}, rw12 = {4, 4, 1, 1}, rw21 = {1, 1},
              rw22 = {1, 1}, rw31 = {1, 4, 4, 6, 4}, rw32 = {6, 5, 3, 6, 1};
  int k1 = 2, k2 = 2, k3 = 1;

  cout << s.miceAndCheese(rw11, rw12, k1) << endl;
  cout << s.miceAndCheese(rw21, rw22, k2) << endl;
  cout << s.miceAndCheese(rw31, rw32, k3) << endl;

  return 0;
}