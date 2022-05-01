#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  int minPartitions(string n) { return *max_element(begin(n), end(n)) - '0'; }
};

int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.minPartitions("82734");
  return 0;
}
