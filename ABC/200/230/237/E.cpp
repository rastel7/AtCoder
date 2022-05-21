#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

const int INF = 1e9;
const ll MOD = 1000000007;
const ll INFll = 1LL << 60;
typedef pair<long, long> PL;
struct Edge {
    ll to;
    ll cost;
};
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる,負のコストの際利用できない
*/
void dijkstra(const vector<vector<Edge>> &G, int s, vector<ll> &dis) {
    int N = G.size();
    dis.resize(N, INFll);
    priority_queue<PL, vector<PL>, greater<PL>>
        pq; //「仮の最短距離、頂点」が小さい順にならぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while(!pq.empty()) {
        PL p = pq.top();
        pq.pop();
        int v = p.second;
        if(dis[v] < p.first)
            continue; //最短経路でなければ無視
        for(auto &e : G[v]) {
            if(dis[e.to] >
               dis[v] + e.cost) { //最短距離候補ならpriority_queueに追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> H(N);
    REP(i, N) cin >> H[i];
    vector<pair<ll, ll>> H_g(N);
    REP(i, N) { H_g[i] = make_pair(H[i], i); }
    sort(H_g.begin(), H_g.end(),
         [](pair<ll, ll> l, pair<ll, ll> r) { return l.first < r.first; });
    vector<vector<Edge>> G(N);

    REP(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(H[u] > H[v]) {
            ll diff = H[u] - H[v];
            G[u].emplace_back(Edge{v, -1 * diff});
            G[v].emplace_back(Edge{u, 2 * diff});
        } else {
            ll diff = H[v] - H[u];
            G[v].emplace_back(Edge{u, -1 * diff});
            G[u].emplace_back(Edge{v, 2 * diff});
        }
    }
    vector<ll> dis;
    dijkstra(G, 0, dis);
    ll ans = 1e18;
    for(auto d : dis) {
        ans = min(ans, d);
    }
    cout << ans * -1 << endl;
}