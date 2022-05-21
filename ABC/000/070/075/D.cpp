#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> X(N), Y(N);
  REP(i, N)cin >> X[i] >> Y[i];
  set<ll> Xs;
  REP(i, N)Xs.insert(X[i]);
  if(Xs.size() == 1) {
    Xs.insert(*Xs.begin() + 1);
  }
  ll ans = LONG_LONG_MAX;
  for(auto xl : Xs) {
    for(auto xr : Xs) {
      if(xl >= xr)continue;
      ll cnt = 0;
      vector<ll> ys;
      REP(i, N) {
        if(xl <= X[i] && X[i] <= xr) {
          ys.emplace_back(Y[i]);
          cnt++;
        }
      }
      if(cnt < K)continue;
      sort(ys.begin(), ys.end());
      ll tmp = 1e18;
      for(int i = K;i <= ys.size();++i) {
        tmp = min(tmp, ys[i - 1] - ys[i - K]);
      }
      ans = min(tmp * (xr - xl), ans);
    }
  }
  cout << ans << endl;
}