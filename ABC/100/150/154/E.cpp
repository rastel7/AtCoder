#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll dp[2][5][110];
int main() {
  string S;
  cin >> S;
  int K,N;
  cin >> K;
  N= S.size();
  dp[0][0][0] = 1;
  for(int i = 0;i < S.size();++i) {
    //dp[0][0][i]=1;
    REP(k, 4) {
      if(S[i] != '0') {
        dp[1][k][i + 1] += dp[0][k][i];
        for(int j = 1;j < S[i] - '0';++j) {
          dp[1][k+1][i + 1] += dp[0][k][i];
        }
        dp[0][k+1][i + 1] += dp[0][k][i];
      } else {
        dp[0][k][i + 1] += dp[0][k][i];
      }
      dp[1][k][i + 1] += dp[1][k][i];
      for(int j = 1;j <= 9;++j) {
        dp[1][k+1][i + 1] += dp[1][k][i];
      }
    }
   // cout<<dp[0][K][i+1]+dp[1][K][i+1]<<endl;
  }
  cout<<dp[0][K][S.size()]+dp[1][K][S.size()]<<endl;
}