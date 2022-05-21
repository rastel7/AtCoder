#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<tuple<ll, ll, ll>> Query[101010];
ll ans[101010];
ll X[101010];
vector<vector<int>> G;
vector<ll> dfs(int id, int prev) {
  /*if(G[id].size() == 1 && id != 0) {
    if(!Query[id].empty()) {
      ans[get<2>(Query[id][0])] = X[id];
    }
    vector<ll> ret = { X[id] };
    return ret;
  }*/
  vector<ll> sm = { X[id] };
  for(auto nex : G[id]) {
    if(nex == prev)continue;
    auto v = dfs(nex, id);
    for(auto a : v) {
      sm.emplace_back(a);
    }
    sort(sm.begin(), sm.end(), greater());
    while(sm.size() > 23) {
      sm.pop_back();
    }
  }
  for(auto [id, num, q] : Query[id]) {
    ans[q] = sm[num - 1];
  }
  return sm;
}
int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N - 1), B(N - 1);
  G.resize(N);
  REP(i, N)cin >> X[i];
  REP(i, N - 1) {
    cin >> A[i] >> B[i], A[i]--, B[i]--;
    G[A[i]].emplace_back(B[i]);
    G[B[i]].emplace_back(A[i]);
  }
  REP(i, Q) {
    ll v, k;
    cin >> v >> k, v--;
    Query[v].emplace_back(make_tuple(v, k, i));
  }
  dfs(0, -1);
  REP(i, Q) {
    cout << ans[i] << endl;
  }
}