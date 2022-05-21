#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
using mint = modint998244353;
mint dp[1024][1024][11] = { 0 };
int main() {
  auto print_ans = [&](int x) {
    mint ans = 0;
    REP(i, 1024) {
      REP(j, 10)ans += dp[x][i][j];
    }
    cout << ans.val() << endl;
  };
  int N;
  cin >> N;
  string S;
  cin >> S;
  REP(i, N) {
    int x = S[i] - 'A';
    REP(u, 1024) {
      REP(j, 10) {
        dp[i + 1][u][j] += dp[i][u][j];
        if(j == x) {
          dp[i + 1][u][j] += dp[i][u][j];//同じところは選ぶか選ばないかで答えが2倍
        }
      }
    }
    //別のところから取る  
    for(int v = 0;v < 1024;++v) {
      if(v & (1 << x))continue;
      REP(j, 10)
        dp[i + 1][v | (1 << x)][x] += dp[i][v][j];
    }
    dp[i + 1][(1 << x)][x]++;
  }
  print_ans(N);
}