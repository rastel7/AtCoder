#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, W;
  cin >> N >> W;
  vector<pair<ll, ll>> V(N);
  REP(i, N)cin >> V[i].first >> V[i].second;
  sort(V.begin(), V.end(), greater<>());
  ll ans = 0;
  REP(i, N) {
    ll tmp = min(W, V[i].second);
    ans += tmp * V[i].first;
    W -= tmp;
  }
  cout << ans << endl;
}