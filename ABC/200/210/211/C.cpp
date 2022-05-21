#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const int MAX_N = (int)1e5 + 100;
mint dp[10][MAX_N];
const string c = "chokudai";
int main() {
  string S;
  cin >> S;
  dp[0][0] = 1;
  REP(i, S.size()) {
    REP(j, c.size()) {
      dp[j][i + 1] += dp[j][i];
      if(S[i] == c[j])dp[j + 1][i + 1] += dp[j][i];
    }
    dp[c.size()][i + 1] += dp[c.size()][i];
  }
  cout << dp[c.size()][S.size()].val() << endl;
}