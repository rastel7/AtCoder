#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, M;
  cin >> N >> M;
  set<pair<ll, ll>> s;
  map<int, set<pair<ll, ll>> > mps;
  set<ll> ys;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    s.insert({ a,b });
    mps[a].insert({ a,b });
    ys.insert(a);
  }
  set<ll> pos = { N };
  for(auto y2 : ys) {
    set<ll> ad, era;
    for(auto [y, x] : mps[y2]) {
      if(pos.count(x)) {
        era.insert(x);
      }
      if(pos.count(x - 1) || pos.count(x + 1)) {
        ad.insert(x);
      }
    }
    for(auto sa : era)pos.erase(sa);
    for(auto sa : ad)pos.insert(sa);
  }
  cout << pos.size() << endl;
}