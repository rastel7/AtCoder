#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll  N, K;
vector<ll> P, C;
ll ans = -1e18;


ll solve(ll id) {
  ll now = id;
  set<int> s;
  ll mx = -1e18, sum = 0;
  int loop_cnt = 0;
  while(!s.count(P[now])) {
    if(loop_cnt >= K)return mx;
    now = P[now];
    s.insert(now);
    sum += C[now];
    mx = max(mx, sum);
    loop_cnt++;
  }
  if(sum <= 0)return mx;
  ll ret = sum * (K / s.size());
  ll cnt = K % s.size();
  mx = ret;
  now = id;
  while(cnt > 0) {
    cnt--;
    now = P[now];
    ret += C[now];
    mx = max(ret, mx);
  }
  return mx;
}
int main() {
  cin >> N >> K;
  P.resize(N), C.resize(N);
  REP(i, N)cin >> P[i], P[i]--;
  REP(i, N)cin >> C[i];
  REP(i, N) {
    ans = max(ans, solve(i));
  }
  cout << ans << endl;
}