#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), wa(N + 1);
  REP(i, N)cin >> A[i];
  REP(i, N)wa[i + 1] = wa[i] + A[i];
  map<ll, ll> mp;
  ll ans = 0;
  REP(i, N + 1) {
    auto now = wa[i];
    ans += mp[now - K];
    mp[wa[i]]++;
  }
 
  cout << ans << endl;
}