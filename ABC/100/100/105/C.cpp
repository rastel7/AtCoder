#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  cin >> N;
  string ans = "";
  ll now = 1;
  while (N != 0) {
    if (abs(N) % (abs(now*2)) != 0) {
      ans += "1";
      N -= now;
    } else {
      ans += "0";
    }
    now *= -2;
  }
  if(ans=="")ans="0";
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}