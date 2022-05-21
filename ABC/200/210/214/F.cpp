//部分列DP
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
using mint = atcoder::modint1000000007;
mint dp[202020];
int main() {
  string S;
  cin >> S;
  int N = S.size();
  dp[0] = 1;
  REP(i, N) {
    for(int j = i - 1;;j--) {
      dp[i + 2] += dp[j + 1];
      if(j == -1 || S[i] == S[j])break;
    }
  }
  mint ans = 0;
  for(int i = 2;i <= S.size() + 1;++i) {
    ans += dp[i];
  }
  cout << ans.val() << endl;
}