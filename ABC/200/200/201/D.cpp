#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll INF = 1e18;
int H, W;
vector<string> S;
ll dp[2010][2010];
ll dfs(int i, int j) {
    if(dp[i][j] != INF)return dp[i][j];
    ll ret;
    auto f = [&](int y, int x) {
        return  S[y][x] == '+' ? 1ll : -1ll;
    };
    if((i + j) % 2 == 0) {
        ret = -INF;
        if(i != H - 1) {
            ret = max(ret, dfs(i + 1, j) + f(i + 1, j));
        }
        if(j != W - 1) {
            ret = max(ret, dfs(i, j + 1) + f(i, j + 1));
        }
    } else {
        ret = INF;
        if(i != H - 1) {
            ret = min(ret, dfs(i + 1, j) - f(i + 1, j));
        }
        if(j != W - 1) {
            ret = min(ret, dfs(i, j + 1) - f(i, j + 1));
        }
    }
    cout << i << " " << j << ":" << ret << endl;
    return dp[i][j] = ret;
}
int main() {
    cin >> H >> W;
    S.resize(H);
    REP(i, H)cin >> S[i];
    REP(i, 2010)REP(j, 2010)dp[i][j] = INF;
    dp[H - 1][W - 1] = 0;
    dfs(0, 0);
    cerr << dp[0][0] << endl;
    if(dp[0][0] == 0) {
        cout << "Draw" << endl;
    } else if(dp[0][0] > 0) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}