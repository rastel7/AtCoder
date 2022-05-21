#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll Q;
  cin >> Q;
  multiset<ll> s;
  while(Q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x;
      cin >> x;
      s.insert(x);
    } else if(t == 2) {
      ll x, k;
      cin >> x >> k;
      auto itr = s.upper_bound(x);
      bool b = 0;
      if(itr == s.begin()) {
        b = 1;
      } else {
        itr--;
      }
      REP(i, k - 1) {
        if(b)break;
        if(itr == s.begin()) {
          b = 1;
          break;
        }
        itr--;
      }
      if(b) {
        cout << -1 << "\n";
      } else {
        cout << *(itr) << "\n";
      }
    } else {
      ll x, k;
      cin >> x >> k;
      auto itr = s.lower_bound(x);
      bool b = 0;
      if(itr == s.end()) {
        b = 1;
      }
      REP(i, k - 1) {
        if(b)break;
        if(itr == s.end()) {
          b = 1;
          break;
        }
        itr++;
        if(itr == s.end()) {
          b = 1;
          break;
        }
      }
      if(itr == s.end()) {
        b = 1;
      }
      if(b) {
        cout << -1 << "\n";
      } else {
        cout << *(itr) << "\n";
      }
    }
  }
}