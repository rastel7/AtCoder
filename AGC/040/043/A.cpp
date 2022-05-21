#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }
int dp[2][110][110];
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    REP(i, 2)REP(j, 110)REP(k, 110)dp[i][j][k] = INF;
    REP(i, h)cin >> S[i];
    if(S[0][0] == '.') {
        dp[0][0][0] = 0;
    } else {
        dp[1][0][0] = 1;
    }
    REP(y, h)REP(x, w) {
        if(S[y][x] == '.') {
            chmin(dp[0][y][x + 1], dp[0][y][x]);
            chmin(dp[0][y][x + 1], dp[1][y][x]);
            chmin(dp[0][y + 1][x], dp[0][y][x]);
            chmin(dp[0][y + 1][x], dp[1][y][x]);
        } else {
            chmin(dp[1][y][x + 1], dp[0][y][x] + 1);
            chmin(dp[1][y][x + 1], dp[1][y][x]);
            chmin(dp[1][y + 1][x], dp[0][y][x] + 1);
            chmin(dp[1][y + 1][x], dp[1][y][x]);
        }
    }
    int mn = INF;
    chmin(mn, dp[0][h - 1][w]);
    chmin(mn, dp[0][h][w - 1]);
    chmin(mn, dp[1][h - 1][w]);
    chmin(mn, dp[1][h][w - 1]);
    cout << mn << endl;
}