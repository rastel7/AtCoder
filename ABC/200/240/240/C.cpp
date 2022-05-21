#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N, X;
  cin >> N >> X;
  set<ll> s = { 0 };
  REP(i, N) {
    set<ll> next;
    ll a, b;
    cin >> a >> b;
    for(auto x : s) {
      ll tmp = a + x;
      if(tmp <= X + 100) {
        next.insert(tmp);
      }
      tmp = b + x;
      if(tmp <= X + 100) {
        next.insert(tmp);
      }
    }
    s = next;
  }
  if(s.count(X)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}