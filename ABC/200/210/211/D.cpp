#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
const ll INFll = 1LL << 60;
typedef pair<long, long> PL;
struct Edge {
    ll to;
    ll cost;
};
const int MAX_N = 2 * 1e5 + 1000;
mint num[MAX_N];
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
    num[0] = 1;
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
                num[e.to] = num[v];
                pq.emplace(dis[e.to], e.to);
            } else if(dis[e.to] == dis[v] + e.cost) {
                num[e.to] += num[v];
            }
        }
    }
}
/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstraRestore(const vector<vector<Edge>> &G, int s, vector<ll> &dis,
                     vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INFll);
    prev.resize(N, -1); // 初期化
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
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

/* get_path(prev, t)
    dijkstraRestore で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for(int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); //逆順なのでひっくり返す
    return path;
}
//参考:https://algo-logic.info/dijkstra/
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b, a--, b--;
        G[a].emplace_back(Edge{b, 1});
        G[b].emplace_back(Edge{a, 1});
    }
    vector<ll> dis;
    dijkstra(G, 0, dis);
    cout << num[N - 1].val() << endl;
}