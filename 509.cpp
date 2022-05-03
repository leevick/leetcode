class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int sum = 0;
    int mone = 1;
    int mtwo = 0;

    for (int i = 2; i <= n; i++) {
      sum = mone + mtwo;
      mtwo = mone;
      mone = sum;
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  s.fib(2);
  return 0;
}
