#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
mint dp[1010][15][15][15];
int main() {
    int N, M;
    cin >> N >> M;
    dp[0][M + 1][M + 1][M + 1] = 1;
    REP(i, N) {
        rep(a, M+1)rep(b, M+1)rep(c, M+1) {
            rep(j, M) {
                if(j <= a) {
                    dp[i + 1][j][b][c] += dp[i][a][b][c];
                } else if(j <= b) {
                    dp[i + 1][a][j][c] += dp[i][a][b][c];
                } else if(j <= c) {
                    dp[i + 1][a][b][j] += dp[i][a][b][c];
                }
            }
        }
    }
    mint ans = 0;
    rep(a, M)rep(b, M)rep(c, M) ans += dp[N][a][b][c];
    cout << ans.val() << endl;
}