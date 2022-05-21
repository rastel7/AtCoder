#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> A(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    A[a].emplace_back(b);
    A[b].emplace_back(a);
  }
  vector<mint> dp(N);
  dp[0] = 1;
  mint sum = 1;
  REP(i, K) {
    vector<mint> next(N);
    REP(j, N) {
      next[j] = sum - dp[j];
      for(auto& k : A[j]) {
        next[j] -= dp[k];
      }
    }
    sum = 0;
    REP(j, N)sum += next[j];
    swap(dp, next);
  }
  cout << dp[0].val() << endl;
}