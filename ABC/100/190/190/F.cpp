#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const int INF = 1e6;
bool chmin(int &a, int b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
int solve(vector<vector<int>> &dp, vector<vector<int>> const &dist, int S,
          int id) {
    if(dp[S][id] != -1)
        return dp[S][id];
    int ret = 1e8;
    REP(i, dist.size()) {
        if((S >> i) == 0)
            continue;
        if(i == id)
            continue;
        ret = min(ret, solve(dp, dist, S & (~(1 << i)), i) + dist[i][id]);
    }
    return dp[S][id] = ret;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    REP(i, M) { cin >> A[i] >> B[i], A[i]--, B[i]--; }
    vector<vector<int>> G(N);
    REP(i, M) { G[A[i]].emplace_back(B[i]); }
    REP(i, M) { G[B[i]].emplace_back(A[i]); }
    int K;
    cin >> K;
    vector<int> C(K);
    REP(i, K) cin >> C[i], C[i]--;
    vector<vector<int>> dist(K, vector<int>(K));
    REP(i, K) {
        int c = C[i];
        queue<pair<int, int>> que;
        vector<int> dist2(N, INF);
        dist2[c] = 0;
        que.push({c, -1});
        while(!que.empty()) {
            auto [id, prev] = que.front();
            que.pop();
            for(auto const &x : G[id]) {
                if(x == prev)
                    continue;
                if(dist2[x] != INF) {
                    continue;
                }
                dist2[x] = dist2[id] + 1;
                que.push({x, id});
            }
        }
        REP(j, K) { dist[i][j] = dist2[C[j]]; }
    }
    vector<vector<int>> dp(1 << K, vector<int>(K, INF));
    REP(i, K) dp[1 << i][i] = 1;
    REP(bit, (1 << K)) {
        REP(i, K) {
            if(bit & (1 << i)) {
                const int bit2 = bit ^ (1 << i);
                REP(j, K) {
                    if(bit2 & (1 << j)) {
                        chmin(dp[bit][i], dp[bit2][j] + dist[i][j]);
                    }
                }
            }
        }
    }
    int ans = *min_element(dp.back().begin(), dp.back().end());
    if(ans >= INF)
        ans = -1;
    cout << ans << endl;
}