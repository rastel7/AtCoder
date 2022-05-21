#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll dp[4000][4000];
int main() {
  ll A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  dp[0][0] = 1;
  REP(i, 3000)REP(j, 3000) {
    if(!dp[i][j])continue;
    if(j + i + 100 * A <= F) {
      dp[i][j + 100 * A] = 1;
    }
    if(j + i + 100 * B <= F) {
      dp[i][j + 100 * B] = 1;
    }
    if(j + i + C <= F && (j / 100) * E >= i + C) {
      dp[i + C][j] = 1;
    }
    if(j + i + D <= F && (j / 100) * E >= i + D) {
      dp[i + D][j] = 1;
    }
  }
  ll a = 100*A, b = 0;

  REP(i, 3010)REP(j, 3010) {
    if(!dp[i][j])continue;
    if(100 * b * (i + j) < 100 * i * (a + b)) {
      a = j, b = i;
    }
  }
  cout << a+b << " " << b << endl;
}