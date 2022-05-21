#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
int N, Q;
int c[501010];
using T = tuple<int, int, int>;
int main() {
  cin >> N >> Q;
  REP(i, N) {
    cin >> c[i];
  }
  vector<T> query(Q);
  REP(i, Q) {
    int u, v;
    cin >> u >> v, u--, v--;
    query[i] = make_tuple(u, v, i);
  }
  sort(query.begin(), query.end(), [](T l, T r) {
    return get<1>(l) < get<1>(r);
    });
  vector<int> ans(Q);
  int id = 0;
  vector<int> checked(N + 1, -1);
  fenwick_tree<ll> tree(N + 1);
  REP(i, N) {
    if(checked[c[i]] != -1) {
      auto id2 = checked[c[i]];
      tree.add(id2, -1);
    }
    tree.add(i, 1);
    checked[c[i]] = i;
    while(get<1>(query[id]) == i && id < Q) {
      ans[get<2>(query[id])] = tree.sum(get<0>(query[id]), get<1>(query[id]) + 1);
      id++;
    }
  }
  REP(i, Q) {
    cout << ans[i] << "\n";
  }
}