#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
// split関数
//  @param s:与えられた一行の入力
//  @param c:区切り文字
vector<string> split(string const& s, char const& c) {
  vector<string> ret;
  string item = "";
  for (auto const& a : s) {
    if (a == c) {
      if (item != "") {
        ret.emplace_back(item);
        item.clear();
        continue;
      }
    }
    item += a;
  }
  if (!item.empty()) {
    ret.emplace_back(item);
  }
  return ret;
}
int main() {}