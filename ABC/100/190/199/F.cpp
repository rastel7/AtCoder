#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int N, M;
int X[110], Y[110], Z[110];
ll dp[(1 << 20)];
int S_count(int x) {
  int ret = 0;
  while(x != 0) {
    if(x & 1)ret++;
    x /= 2;
  }
  return ret;
}
int main() {
  cin >> N >> M;
  REP(i, M) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  dp[0] = 1;
  for(int i = 0;i < (1 << N);++i) {
    REP(j, N) {
      if(i & (1 << j))continue;
      int count = S_count(i) + 1;
      bool ok = 1;
      REP(k, M) {
        if(count > X[k])continue;
        int cnt = 0, cp = i | (1 << j), id = 0;
        while(cp != 0) {
          if(id >= Y[k])break;
          if(cp & 1) {
            cnt++;
          }
          cp /= 2, id++;
        }
        if(cnt > Z[k])ok = false;
      }
      if(ok) {
        dp[i | (1 << j)] += dp[i];
      }
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}