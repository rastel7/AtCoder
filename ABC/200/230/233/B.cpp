#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int l, r;
  cin >> l >> r;
  string s;
  cin >> s;
  reverse(s.begin() + l-1, s.begin() + r);
  cout << s << endl;
}
