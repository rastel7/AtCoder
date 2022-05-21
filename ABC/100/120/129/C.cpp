#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
vector<mint> dp(1e5 + 100);
int main() {
  int N, M;
  cin >> N >> M;
  set<int> s;
  REP(i, M) {
    int a;
    cin >> a;
    s.insert(a);
  }
  dp[0] = 1;
  for(int i = 0;i <= N;++i) {
    if(!s.count(i + 1)) {
      dp[i + 1] += dp[i];
    }
    if(!s.count(i + 2)) {
      dp[i + 2] += dp[i];
    }
  }
  cout << dp[N].val() << endl;
}