#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
template <class T>
vector<vector<T>> warshal(vector<vector<T>> const& G) {
    int N = G.size();
    vector<vector<T>> ret = G;
    for(int i = 0;i < N;++i) {
        for(int j = 0;j < N;++j) {
            for(int k = 0;k < N;++k) {
                if(ret[j][k] > ret[j][i] + ret[i][k]) {
                    ret[j][k] = ret[j][i] + ret[i][k];
                }
            }
        }
    }
    return ret;
}
int main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> perm(R);
    REP(i, R)cin >> perm[i], perm[i]--;
    sort(perm.begin(), perm.end());
    vector<vector<ll>> dist(N, vector<ll>(N, 1e15));
    REP(i, N)dist[i][i] = 0;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c, a--, b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    auto war = warshal(dist);
    ll ans = 1e18;
    do {
        ll tmp = 0;
        REP(i, perm.size() - 1)tmp += war[perm[i]][perm[i + 1]];
        ans = min(ans, tmp);
    } while(next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
}