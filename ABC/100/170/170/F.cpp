#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
ll dy[4] = {0, 1, 0, -1};
ll dx[4] = {1, 0, -1, 0};
int main() {
    ll H, W, K;
    cin >> H >> W >> K;
    ll y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2, x1--, x2--, y1--, y2--;
    vector<string> C(H);
    REP(i, H) cin >> C[i];
    vector<vector<int>> dp(H + 1, vector<int>(W + 1, -1));
    queue<pair<int, int>> que;
    que.push({y1, x1});
    dp[y1][x1] = 0;
    while(!que.empty()) {
        auto [y, x] = que.front();
        if(y == y2 && x == x2) {
            cout << dp[y][x] << endl;
            return 0;
        }
        que.pop();
        REP(i, 4) {
            for(ll j = 1; j <= K; ++j) {
                ll ny = y + dy[i] * j, nx = x + dx[i] * j;
                if(ny < 0 || ny >= H || nx < 0 || nx >= W) {
                    break;
                }
                if(C[ny][nx] == '@')
                    break;
                ll cost = dp[y][x] + 1;
                if(dp[ny][nx] != -1 && cost != dp[ny][nx])
                    break;
                if(dp[ny][nx] == -1)
                    que.push({ny, nx});
                dp[ny][nx] = 1 + dp[y][x];
            }
        }
    }
    cout << dp[y2][x2] << endl;
}