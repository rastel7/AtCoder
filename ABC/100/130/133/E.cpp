#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

vector<int> G[101010];
Combination<mint> comb(101010);
int N, K;
mint dfs(int id, int prev) {
  int can_use_num;
  if(prev == -1) {
    can_use_num = K - 1;
  } else {
    can_use_num = K - 2;
  }
  if(K < G[id].size()) {
    return 0;
  }
  int cnt = G[id].size();
  if(prev != -1)cnt--;
  if(can_use_num < cnt)return 0;
  mint ret = comb.P(can_use_num, cnt);
  for(auto e : G[id]) {
    if(e == prev)continue;
    ret *= dfs(e, id);
  }
  return ret;
}
int main() {
  cin >> N >> K;
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  cout << (K * dfs(0, -1)).val() << endl;
}