#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
struct query {
  ll l, r, i;
};
using S = ll;
S op(S l, S r) {
  return l + r;
}
S e() {
  return 0;
}
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i], A[i]--;
  }
  ll t;
  cin >> t;
  vector<query> Q(t);
  REP(i, t) {
    cin >> Q[i].l >> Q[i].r, Q[i].l--, Q[i].r--;
    Q[i].i = i;
  }
  const ll INF = 1e18;
  Q.push_back(query{ INF,INF,INF });
  sort(Q.begin(), Q.end(), [](query l, query r) {
    return l.r < r.r;
    });
  vector<vector<ll>> colors(N);
  segtree<S, op, e> seg(N + 5);
  segtree<S, op, e> seg2(N + 5);
  ll pos = 0;
  vector<ll> ans(t);
  REP(i, N) {
    colors[A[i]].emplace_back(i);
    if(colors[A[i]].size() % 2 == 0) {
      //追加
      ll id = colors[A[i]][colors[A[i]].size() - 2];
      auto nex = seg.get(id);
      seg.set(id, nex + 1);
      if(colors[A[i]].size() >= 4) {
        id = colors[A[i]][colors[A[i]].size() - 3];
        nex = seg2.get(id);
        seg2.set(id, nex - 1);
        id = colors[A[i]][colors[A[i]].size() - 4];
        nex = seg2.get(id);
        seg2.set(id, nex + 1);
      }
    } else if(colors[A[i]].size() > 2 && colors[A[i]].size() % 2 == 1) {
      ll id = colors[A[i]][colors[A[i]].size() - 2];
      auto nex = seg2.get(id);
      seg2.set(id, nex + 1);
      id = colors[A[i]][colors[A[i]].size() - 3];
      nex = seg2.get(id);
      seg2.set(id, nex - 1);
    }
    while(Q[pos].r == i) {
      if(pos >= t)break;
      ll q_id = Q[pos].i;
      ans[q_id] = seg.prod(Q[pos].l, Q[pos].r + 1) + seg2.prod(Q[pos].l, Q[pos].r + 1);
      pos++;
    }
  }
  REP(i, t) {
    cout << ans[i] << "\n";
  }
}