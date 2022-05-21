#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint998244353;
int G[5010][5010];
mint dp[5010][5010];
int main() {
    int H, W, K;
    cin >> H >> W >> K;
    REP(i, K) {
        int y, x;
        char c;
        cin >> y >> x >> c, y--, x--;
        if(c == 'X')G[y][x] = 1;
        if(c == 'R')G[y][x] = 2;
        if(c == 'D')G[y][x] = 3;
    }
    int C = H * W - K;
    dp[0][0] = 1;
    mint inv = mint(3).inv();
    REP(y, H)REP(x, W) {

        if(G[y][x] == 1) {
            dp[y + 1][x] += dp[y][x];
            dp[y][x + 1] += dp[y][x];
            continue;
        }
        if(G[y][x] == 2) {
            dp[y][x + 1] += dp[y][x];
            continue;
        }
        if(G[y][x] == 3) {
            dp[y + 1][x] += dp[y][x];
            continue;
        }
        dp[y + 1][x] += dp[y][x] * 2 * inv;
        dp[y][x + 1] += dp[y][x] * 2 * inv;
    }
    mint ans = (dp[H - 1][W - 1]) * mint(3).pow(C);
    cout << ans.val() << endl;
}