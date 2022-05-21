#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll calc_sum(ll l, ll r) {
  return (r - l + 1) * (l + r) / 2;
}
ll search(ll i, ll l, ll r, ll kosuu) {
  if(kosuu <= 0)return 0;
  //i回での最高
  ll l_1 = r - (kosuu) / i;
  if(l_1 < 0) {
    return calc_sum(0, r) * i;
  }
  ll ret = calc_sum(l_1 + 1, r) * i;
  ll remain = kosuu - (r - l_1) * i;
  ret += (l_1 * remain);
  return ret;
}
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  ll ans = 0;
  sort(A.begin(), A.end(), greater<>());
  ll prev = A[0];
  for(ll i = 1;i < N;++i) {
    ll now = A[i];
    if(now != prev) {
      ll tmp = i * (prev - now);
      if(K - tmp < 0) {
        ans += search(i, now + 1, prev, K);
        K = 0;
        break;
      }
      else {
        ans += calc_sum(now + 1, prev) * i;
        K -= tmp;
      }
    }
    else {
      /*K--;
      ans += A[i];
      if(K == 0)break;
      */
    }
    prev = A[i];
  }
  ans += search(N, 0, prev, K);
  cout << ans << endl;
}