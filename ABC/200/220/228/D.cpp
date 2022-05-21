#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll N = 1048576;
int main() {
  ll Q;
  cin >> Q;
  map<ll, ll> warp;
  map<ll, ll> mp;
  vector<ll> ans;
  while(Q--) {
    int t;
    cin >> t;
    ll x;
    cin >> x;
    if(t == 1) {
      ll h = x % N;
      ll def_id = x % N;
      vector<int> katei;
      while(mp.count(h)) {
        katei.emplace_back(h);
        if(warp.count(h)) {
          h = warp[h] + 1;
          continue;
        }
        h = (h + 1) % N;
      }
      for(auto& kt : katei) {
        warp[kt] = h;
      }
      mp[h] = x;
    } else {
      x %= N;
      if(mp.count(x)) {
        ans.emplace_back(mp[x]);
      } else {
        ans.emplace_back(-1);
      }
    }
  }
  for(auto& x : ans) {
    cout << x << "\n";
  }
}