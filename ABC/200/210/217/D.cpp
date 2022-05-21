#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
struct S {
  ll value;
  ll size;
};
using F = ll;
S op(S a, S b) { return { a.value + b.value, a.size + b.size }; }
S e() { return { 0, 0 }; }
S mapping(F f, S x) { return { x.value - x.size * f, x.size }; }
F composition(F f, F g) { return f - g; }
F id() { return 0; }


int main() {
  ll L, Q;
  cin >> L >> Q;
  vector<P> query(Q);
  vector<int> x_list;
  REP(i, Q) {
    cin >> query[i].first >> query[i].second;
    if(query[i].first == 1) {
      x_list.emplace_back(query[i].second);
    }
  }
  if(x_list.size()==0){
    REP(i,Q){
      cout<<L<<endl;
    }
    return 0;
  }
  sort(x_list.begin(), x_list.end());
  x_list.erase(unique(x_list.begin(), x_list.end()), x_list.end());
  vector<ll> lengths(x_list.size() + 1);
  REP(i, lengths.size()) {
    if(i == 0) {
      lengths[i] = x_list[i];
    } else {
      lengths[i] = x_list[i] - x_list[i - 1];
    }
  }
  lengths[x_list.size()] = L - x_list.back();
  dsu uf(x_list.size() + 1);

  vector<ll> ans;
  for(int i = Q - 1;i >= 0;i--) {
    int c = query[i].first, x = query[i].second;
    if(c == 2) {
      int id = (lower_bound(x_list.begin(), x_list.end(), x) - x_list.begin());
      id = uf.leader(id);
      ans.emplace_back(lengths[id]);
    } else {
      int id = (lower_bound(x_list.begin(), x_list.end(), x) - x_list.begin());
      int id2 = uf.leader(id + 1);
      id = uf.leader(id);
      ll tmp = lengths[id];
      lengths[id] += lengths[id2], lengths[id2] += tmp;
      uf.merge(id,id2);
    }
  }
  reverse(ans.begin(), ans.end());
  for(auto& i : ans)cout << i << endl;
}