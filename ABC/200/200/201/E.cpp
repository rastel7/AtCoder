#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, ll> P;
const int INF = 1e9;
const ll MOD = 1000000007;

ll dist[(int)2e5 + 100];
void dfs(int id, int prev, ll cost, vector<vector<P>>& G) {
    dist[id] = (dist[prev] ^ cost);
    for(auto& e : G[id]) {
        if(e.first == prev) continue;
        dfs(e.first, id, e.second, G);
    }
};
int main() {
    int N;
    cin >> N;
    vector<ll> u(N - 1), v(N - 1), w(N - 1);
    REP(i, N - 1)cin >> u[i] >> v[i] >> w[i], v[i]--, u[i]--;
    vector<vector<P>> G(N);
    REP(i, N - 1)G[u[i]].emplace_back(P(v[i], w[i]));
    REP(i, N - 1)G[v[i]].emplace_back(P(u[i], w[i]));
    dfs(0, 0, 0, G);
    mint ans = 0;
    for(ll i = 0;i < 62;++i) {
        mint cnt = 0;
        for(int j = 0;j < N;++j) {
            if((dist[j] >> i) & 1)cnt++;
        }
        ans += mint(2).pow(i) * cnt * (N - cnt);
    }
    cout << ans.val() << endl;
}