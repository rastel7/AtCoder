#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

template <typename T>
struct compress {
  vector<T> origin, vals;
  compress(vector<T> vec) {
    origin = vec;
    vals = vec;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(int i = 0;i < (int)origin.size();++i) {
      origin[i] = lower_bound(vals.begin(), vals.end(), origin[i]) - vals.begin();
    }
  }
  T ret_id(T val) {
    //値を入力すると何番目の値かを返す
    return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
  }
  T ret_val(T id) {
    //何番目の値化を入力するとidを返す
    return vals[id];
  }
};
ll op(ll l, ll r) { return l + r; }
ll e() { return 0; }
int main() {
  int  N;
  cin >> N;
  vector<ll> comp;
  vector<pair<ll, ll>> A(N);
  REP(i, N)cin >> A[i].first, comp.emplace_back(A[i].first);
  REP(i, N)cin >> A[i].second, comp.emplace_back(A[i].second);
  sort(comp.begin(), comp.end());
  compress comps(comp);
  REP(i, N) {
    A[i].first = comps.ret_id(A[i].first);
    A[i].second = comps.ret_id(A[i].second);
  }
  sort(A.begin(), A.end(), [](pair<ll, ll> l, pair<ll, ll>r) {
    if(l.first == r.first) {
      return l.second > r.second;
    }
    return l.first < r.first;
    });
  segtree<ll, op, e> seg(N * 2 + 1);
  ll ans = 0;
  REP(i, N) {
    ll cnt = 1;
    while(i + 1 < N && A[i] == A[i + 1]) {
      cnt++, i++;
    }
    seg.set(A[i].second, seg.get(A[i].second) + cnt);
    ll l = cnt * seg.prod(A[i].second, 2 * N);
    ans += l;
  }
  cout << ans << endl;
}