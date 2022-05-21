#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, T;
  cin >> N >> T;
  vector<ll> A(N);
  REP(i, N)cin >> A[i];
  T /= 2;
  vector<ll> dp(N + 10, -1e18);
  REP(i, N) {
    dp[i + 1] = max(dp[i], -A[i] * T);
  }
  ll mx = 0;
  for(int i = 2;i <= N;++i) {
    mx = max(dp[i] + T * A[i - 1], mx);
  }
  int ans = 0;
  REP(i, N+1) {
    if(mx == dp[i] + T * A[i - 1]) {
      ans++;
    }
  }
  cout << ans << endl;
}