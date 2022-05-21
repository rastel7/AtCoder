#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<int> G[210101];
int ans[210101], a[210101];
int dp[210101];
const int MAX_N = 210101;
const int INF = 1e9;
int N;
void dfs(int id, int prev) {
    auto itr = lower_bound(dp, dp + N, a[id]);
    int push_id = itr - dp;
    int prev_num = dp[push_id];
    dp[push_id] = a[id];
    ans[id] = lower_bound(dp, dp + N, INF) - dp;
    for(auto a : G[id]) {
        if(a == prev)continue;
        dfs(a, id);
    }

    dp[push_id] = prev_num;
}
int main() {
    cin >> N;
    REP(i, MAX_N)dp[i] = INF;
    REP(i, N) {
        cin >> a[i];
    }
    REP(i, N - 1) {
        int u, v;
        cin >> u >> v, u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(0, -1);
    REP(i, N)cout << ans[i] << "\n";
}