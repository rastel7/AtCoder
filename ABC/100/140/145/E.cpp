#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
int dp[2][6200][6200];
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> A(n), B(n);
    REP(i, n)cin >> A[i] >> B[i];
    REP(i, 2)REP(j, 3100)REP(k, 3100)dp[i][j][k] = 0;
    REP(i, n) {
        REP(j, t) {
            chmax(dp[0][i + 1][j], dp[0][i][j]);
            chmax(dp[1][i + 1][j], dp[1][i][j]);
            if(j + A[i] < t) {
                chmax(dp[0][i + 1][j + A[i]], dp[0][i][j] + B[i]);
                chmax(dp[1][i + 1][j + A[i]], dp[1][i][j] + B[i]);
            }
            chmax(dp[1][i + 1][j], dp[0][i][j] + B[i]);
        }
    }
    int ans = 0;
    REP(j, t) {
        chmax(ans, dp[1][n][j]);
    }
    cout << ans << endl;
}