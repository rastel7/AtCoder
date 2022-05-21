#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  vector<ll> wa(N + 1);
  REP(i, N)wa[i + 1] = (wa[i] + A[i]) % K;
  ll ans = 0;
  map<ll, ll> mp;
  vector<ll> prev(N + 1);
  REP(i, N + 1) {
    ll r = (wa[i] - i + (ll)1e9 * K) % K;
    if(i >= K) {
      mp[prev[i - K]]--;
    }
    ans += mp[r];
    prev[i] = r;
    mp[r]++;
  }
  cout << ans << endl;
}