#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
template<class T>
void chmin(T& a, T b) {
  if(a > b)a = b;
}
map<ll, ll> mp;
ll dfs(ll x, ll id, vector<ll> const& A) {
  if(mp.count(x))return mp[x];
  ll ret = 1e18;
  if(id == A.size() - 1)return x / A.back();
  if(x == 0)return 0;
  ll m = (x % A[id + 1]) / A[id];

  chmin(ret, m + dfs(x / A[id + 1] * A[id + 1], id + 1, A));
  if(m != 0)chmin(ret, A[id + 1] / A[id] - m + dfs((1 + x / A[id + 1]) * A[id + 1], id + 1, A));

  return mp[x] = ret;
}
int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  cout << dfs(M, 0, A) << endl;
}