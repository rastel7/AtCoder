#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N;
ll ans = -1e15;
int use[20];
ll dfs2(int cnt, int start, ll now, vector<vector<ll>> const &A) {

    if(cnt == N) {
        ans = max(ans, now);
        return 0;
    }
    for(int i = start; i < 2 * N; ++i) {
        if(use[i] != -1)
            continue;
        for(int j = i + 1; j < 2 * N; ++j) {
            if(use[j] != -1)
                continue;
            ll a = A[min(i, j)][max(i, j)];
            if(a == -1)
                continue;
            use[i] = 1, use[j] = 1;
            dfs2(cnt + 1, i + 1, now ^ a, A);
            use[i] = -1, use[j] = -1;
        }
        return 0;
    }
    return 0;
}
int main() {
    REP(i, 20) use[i] = -1;
    cin >> N;
    vector<vector<ll>> A(2 * N, vector<ll>(2 * N, -1));
    REP(i, 2 * N - 1) REP(j, 2 * N - 1 - i) cin >> A[i][1 + j + i];
    dfs2(0, 0, 0, A);
    cout << ans << endl;
}