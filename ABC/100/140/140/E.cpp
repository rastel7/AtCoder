#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  ll N;
  cin >> N;
  vector<ll> P(N);
  REP(i, N)cin >> P[i];
  vector<pair<ll, ll>> A(N);
  REP(i, N)A[i] = { P[i],i };
  sort(A.begin(), A.end(), greater<>());
  set<ll> s = { -2,-1,N ,N + 1 };
  ll ans = 0;
  for(auto [x, id] : A) {
    s.insert(id);
    ll l1, l2, r1, r2;
    auto itr = s.lower_bound(id);
    l2 = *(--itr);
    l1 = *(--itr);
    itr = s.lower_bound(id);
    r1 = *(++itr);
    r2 = *(++itr);
    if(l2 != -1) {
      ans += (l2 - l1) * (r1 - id) * x;
    }
    if(r1 != N) {
      ans += (r2 - r1) * (id - l2) * x;
    }
    cerr << ans << endl;
  }
  cout << ans << endl;
}