#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll wa[310000];
ll N, M;
vector<ll> A;
bool f(ll x) {
  ll ans = 0;
  REP(i, N) {
    ll id = max<ll>(0, x - A[i]);
    ans += wa[id];
  }
  return ans >= M;
}
int main() {
  cin >> N >> M;
  A.resize(N);
  REP(i, N) {
    cin >> A[i];
    wa[A[i]]++;
  }
  sort(A.begin(), A.end());
  for(ll i = 109000;i >= 0;i--)wa[i] += wa[i + 1];
  ll l = -1, r = 3e5 + 100;
  while(r - l > 1) {
    ll mid = l + (r - l) / 2;
    if(f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  vector<ll> Wa2(N + 1);
  for(int i = N - 1;i >= 0;i--)Wa2[i] = Wa2[i + 1] + A[i];
  ll H = l + 1;
  ll ans = 0, cnt_sum = 0;
  REP(i, N) {
    ll dif = H - A[i];
    auto itr = lower_bound(A.begin(), A.end(), dif);
    if(itr == A.end())continue;
    ll cnt = N - (itr - A.begin()) ;
    ans += Wa2[(itr - A.begin())] + A[i] * cnt;
    cnt_sum += cnt;
  }
  ans += (M - cnt_sum) * l;
  cout << ans << endl;
}