#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, j, n) for(int i = j; i < (int)(n); i++)
using ll = long long;
ll infl = 1e17;
using namespace std;
int N, M, S;
vector<pair<int, int>> E[50];
int A[101], B[101], C[50], D[50];
ll dist[50][3010];
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
bool vis[50][3010];
ll ans[50];
bool chmin(int &a, int const b) {
    if(a > b) {
        a = min(a, b);
        return true;
    }
    return false;
}
bool chmin(int &a, ll const b) {
    if(a > b) {
        a = min<ll>(a, b);
        return true;
    }
    return false;
}
bool chmin(ll &a, ll const b) {
    if(a > b) {
        a = min(a, b);
        return true;
    }
    return false;
}
bool chmin(ll &a, int const b) {
    if(a > b) {
        a = min<ll>(a, b);
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N >> M >> S;
    chmin(S, 3000);
    rep(i, 0, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cin >> A[i] >> B[i];
        E[u].push_back({v, i});
        E[v].push_back({u, i});
    }
    rep(i, 0, N) cin >> C[i] >> D[i];

    rep(i, 0, N) rep(s, 0, 3001) dist[i][s] = infl;
    rep(i, 0, N) rep(s, 0, 3001) vis[i][s] = false;
    rep(i, 0, N) ans[i] = infl;

    min_priority_queue<pair<ll, int>> que;

    dist[0][S] = 0;
    que.push({0, 0 * 5010 + S});

    while(!que.empty()) {
        auto q = que.top();
        que.pop();

        ll cst = q.first;
        int cu = q.second / 5010;
        int s = q.second % 5010;

        if(vis[cu][s])
            continue;
        vis[cu][s] = true;

        chmin(ans[cu], cst);

        for(auto p : E[cu]) {
            int to = p.first;
            int i = p.second;
            if(s < A[i])
                continue;

            ll cst2 = cst + B[i];
            if(chmin(dist[to][s - A[i]], cst2))
                que.push({dist[to][s - A[i]], to * 5010 + s - A[i]});
        }

        ll cst2 = cst + D[cu];
        int s2 = min(3000, s + C[cu]);
        if(chmin(dist[cu][s2], cst2))
            que.push({dist[cu][s2], cu * 5010 + s2});
    }

    rep(i, 1, N) printf("%lld\n", ans[i]);
}