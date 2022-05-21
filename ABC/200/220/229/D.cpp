#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  string S;
  cin >> S;
  ll K;
  cin >> K;
  ll r = 0, ans = 0;
  vector<ll> wa(S.size() + 1);
  REP(i, S.size()) {
    wa[i + 1] = wa[i];
    if(S[i] == '.')wa[i + 1]++;
  }
  REP(l, S.size()) {
    while(r < S.size() && wa[r + 1] - wa[l] <= K) {
      r++;
    }
    //cerr << l << " " << r << endl;
    ans = max(ans, r - l);
  }
  cout << ans << endl;
}