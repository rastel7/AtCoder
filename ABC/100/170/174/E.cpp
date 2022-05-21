#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N, K;
vector<ll> A;
bool f(ll mx) {
  ll cnt = 0;
  for(auto const& a : A) {
    cnt += (a-1) / mx;
  }
  return cnt <= K;
}
int main() {
  cin >> N >> K;
  A.resize(N);
  REP(i, N) {
    cin >> A[i];
  }
  ll l = 0, r = 1e15;
  while(r - l > 1) {
    ll mid = l + (r - l) / 2;
    if(f(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
}