#include "leetcode.hpp"

class Solution {
 public:
  bool parseBoolExpr(string expression) {
    auto s = stack<char>();
    for (auto c : expression) {
      if (c == ')') {
        vector<bool> operands;
        while (s.top() == 't' || s.top() == 'f') {
          operands.push_back(s.top() == 't' ? true : false);
          s.pop();
        }

        switch (s.top()) {
          case '!':
            s.pop();
            s.push(!operands.back() ? 't' : 'f');
            break;
          case '&': {
            s.pop();
            bool ret = true;
            for (auto b : operands) {
              if (!b) {
                ret = false;
                break;
              }
            }
            s.push(ret ? 't' : 'f');
          } break;
          case '|': {
            s.pop();
            bool ret = false;
            for (auto b : operands) {
              if (b) {
                ret = true;
                break;
              }
            }
            s.push(ret ? 't' : 'f');
          } break;
          default:
            break;
        }

      } else if (c == '(' || c == ',') {
        continue;
      } else {
        s.push(c);
      }
    }
    return s.top() == 't' ? true : false;
  }
};

int main(int argc, char const *argv[]) {
  string t1 = "&(|(f))", t2 = "|(f,f,f,t)", t3 = "!(&(f,t))",
         t4 = "|(f,&(t,t))";
  Solution s;
  auto ret = s.parseBoolExpr(t1);
  ret = s.parseBoolExpr(t2);
  ret = s.parseBoolExpr(t3);
  ret = s.parseBoolExpr(t4);
  return 0;
}
