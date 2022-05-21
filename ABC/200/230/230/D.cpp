#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, D;
  cin >> N >> D;
  vector<pair<ll, ll>> V(N);
  REP(i, N) {
    cin >> V[i].second >> V[i].first;
  }
  sort(V.begin(), V.end());
  ll ans = 0;
  ll now = -1;
  for(auto [r, l] : V) {
    if(l <= now)continue;
    ans++;
    now = r + D - 1;
  }
  cout << ans << endl;
}