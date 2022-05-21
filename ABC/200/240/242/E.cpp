#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    string S;
    cin >> N >> S;
    vector<vector<mint>> dp((N + 1) / 2 + 1, vector<mint>(2));
    dp[0][1] = 1;
    REP(i, (N + 1) / 2) {
      dp[i + 1][0] += dp[i][0] * 26;
      int dif = S[i] - 'A';
      dp[i + 1][0] += dp[i][1] * dif;
      dp[i + 1][1] += dp[i][1];
    }
    mint ans = dp[(N + 1) / 2][0];
    string t = "";
    REP(i, N) {
      if(i < (N + 1) / 2)
        t += S[(i)];
      else
        t += S[N - i - 1];
    }
    bool kaibun = 1;
    REP(i, N) {
      if(S[i] != S[N - 1 - i]) {
        kaibun = 0;
      }
    }

    //if(kaibun)ans++;
    if(t <= S)ans++;
    cout << ans.val() << endl;
  }
}
