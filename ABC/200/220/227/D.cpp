#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
bool f(vector<ll> const& A, ll abb, ll obj) {
  for(auto& x : A) {
    if(x > obj)continue;
    abb -= obj - x;
    if(abb < 0)return 0;
  }
  return 1;
}
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  priority_queue<ll, vector<ll>, greater<>> que;
  sort(A.rbegin(), A.rend());
  ll sm = 0;
  for(ll i = N - 1;i >= K;--i) {
    sm += A.back();
    A.pop_back();
  }
  ll l = 0, r = 1e18;
  while(r - l > 1) {
    ll mid = l + (r - l) / 2;
    if(f(A, sm, mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
}