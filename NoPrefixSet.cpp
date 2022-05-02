#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(vector<string> words) {
  unordered_set<string> pre;
  //   unordered_set<string> check;

  for (auto w : words) {
    auto it = pre.find(w);
    if (it != pre.end()) {
      cout << "BAD SET" << endl;
      cout << w << endl;
      return;
    }

    // Check existing prefix
    for (auto p : pre) {
      auto mlen = min(w.length(), p.length());
      if (w.compare(0, mlen, p, 0, mlen) == 0) {
        if (mlen == w.length()) {
          cout << "BAD SET" << endl;
          cout << p << endl;
          return;
        } else {
          cout << "BAD SET" << endl;
          cout << w << endl;
          return;
        }
      }
    }
    pre.insert(w);
  }

  cout << "GOOD SET" << endl;
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<string> words(n);

  for (int i = 0; i < n; i++) {
    string words_item;
    getline(cin, words_item);

    words[i] = words_item;
  }

  noPrefix(words);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
