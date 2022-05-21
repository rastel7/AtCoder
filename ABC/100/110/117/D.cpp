#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  ll x = 0;
  for(ll i = 60;i >= 0;i--) {
    if((x|(((ll)1) << i)) > K)continue;
    int zero = 0, one = 0;
    REP(j, N) {
      if((A[j] >> i) & 1) {
        one++;
      } else {
        zero++;
      }
    }
    if(one < zero) {
      x |= (((ll)1) << i) ;
    }
  }
  ll ans = 0;
  REP(i, N)ans += A[i] ^ x;
  cout << ans << endl;
}