#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

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
void dijkstra(const vector<vector<Edge>>& G, int s, vector<ll>& dis) {
    int N = G.size();
    dis.resize(N, INFll);
    priority_queue<PL, vector<PL>, greater<PL>>
        pq;  //「仮の最短距離、頂点」が小さい順にならぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while(!pq.empty()) {
        PL p = pq.top();
        pq.pop();
        int v = p.second;
        if(dis[v] < p.first) continue;  //最短経路でなければ無視
        for(auto& e : G[v]) {
            if(dis[e.to] > dis[v] + e.cost) {  //最短距離候補ならpriority_queueに追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}
int N, M;
int A[1010], B[1010];
char C[1010];
ll index(int i, int j) {
    return i * (N + 5) + j;
}
int main() {
    cin >> N >> M;
    vector<vector<Edge>> G(1010 * 1010);
    REP(i, M) {
        cin >> A[i] >> B[i] >> C[i];
    }
    REP(i, M)REP(j, M) {
        if(C[i] != C[j])continue;
        G[index(A[i], A[j])].emplace_back(Edge{ index(B[i], B[j]),2 });
        G[index(B[i], B[j])].emplace_back(Edge{ index(A[i], A[j]),2 });
        G[index(A[i], B[j])].emplace_back(Edge{ index(B[i], A[j]),2 });
        G[index(B[i], A[j])].emplace_back(Edge{ index(A[i], B[j]),2 });
    }
    ll ans = 1e18;
    vector<ll> dis;
    dijkstra(G, index(1, N), dis);
    REP(i, N) {
        ans = min(ans, dis[index(i, i)]);
    }
    REP(i, M) {
        ans = min(ans, dis[index(A[i], B[i])] + 1);
        ans = min(ans, dis[index(B[i], A[i])] + 1);
    }
    if(ans == 1e18)ans = -1;
    cout << ans << endl;
}