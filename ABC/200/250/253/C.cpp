#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll Q;
  cin >> Q;
  map<ll, ll> mp;
  priority_queue<ll, vector<ll>, greater<>> queue;
  set<ll> s;
  vector<ll> ans;
  REP(_, Q) {
    ll i;
    cin >> i;
    if (i == 1) {
      ll x;
      cin >> x;
      mp[x]++;
      s.insert(x);
    } else if (i == 2) {
      ll x, c;
      cin >> x >> c;
      ll num = min(c, mp[x]);
      mp[x] -= num;
      if (mp[x] == 0) {
        mp.erase(x);
        s.erase(x);
      }
    } else {
      ll mn = (*s.begin());
      ll mx = (*s.rbegin());
      ans.emplace_back(mx - mn);
    }
  }
  for (auto a : ans) {
    cout << a << "\n";
  }
}