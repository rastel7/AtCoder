#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<ll> A;
vector<ll> wa;
pair<ll, ll> f(int l, int r) {
  ll f_l = l, f_r = r;
  while(r - l > 1) {
    int mid = l + (r - l) / 2;
    ll diff1 = wa[mid] - wa[f_l];
    ll diff2 = wa[f_r] - wa[mid];
    if(diff1 < diff2) {
      l = mid;
    } else {
      r = mid;
    }
  }
  auto dy = [&](pair<ll, ll> p) {
    return max(p.first, p.second) - min(p.first, p.second);
  };
  auto x = make_pair(wa[f_r] - wa[l], wa[l] - wa[f_l]);
  auto y = make_pair(wa[f_r] - wa[r], wa[r] - wa[f_l]);
  return dy(x) < dy(y) ? x : y;
}
int main() {
  int N;
  cin >> N;
  A.resize(N);
  REP(i, N)cin >> A[i];
  ll ans = 1e18;
  wa.resize(N + 1);
  REP(i, N)wa[i + 1] += wa[i] + A[i];
  REP(i, N + 1) {
    if(i <= 1 || i >= N - 1)continue;
    auto x = f(0, i);
    auto y = f(i, N);
    ans = min(ans, max({ x.first,y.first,x.second,y.second }) - min({ x.first,y.first,x.second,y.second }));
  }
  cout << ans << endl;
}