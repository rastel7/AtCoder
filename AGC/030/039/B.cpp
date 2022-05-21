#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int N;
string S[300];
int color[300];
bool dfs(int id, int c) {
    if(color[id] == 0) {
        color[id] = c;
    } else {
        return color[id] == c;
    }
    int nex;
    if(c == 1)nex = 2;
    else nex = 1;
    REP(i, N) {
        if(S[i][id] == '1') {
            if(!dfs(i, nex)) return false;
        }
    }
    return true;
}


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
vector<ll>  dijkstra(const vector<vector<Edge>>& G, int s) {
    int N = G.size();
    vector<ll> dis;
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
    return dis;
}
const int INF = 1e8;
template <class T>
/*  ワーシャルフロイド
    O(V)，全店最短路
    dis[i][i]=0を入力しておく
    dis[i][j]に，辺i-jのコストを入力しておく
    辺がなかったらINF
    負の閉路があったらdis[i][i]が負になるものが存在する*/
void warshall_floyd(T& dis) {
    int V = dis.size();
    REP(k, V)
        REP(i, V) {
        if(dis[i][k] == INF) continue;
        REP(j, V) {
            if(dis[k][j] == INF) continue;
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}

int main() {
    cin >> N;
    REP(i, N)cin >> S[i];
    if(!dfs(0, 1)) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> G(N, vector<int>(N, INF));
    REP(i, N)G[i][i] = 0;
    REP(i, N)REP(j, N) {
        if(S[i][j] == '1') G[i][j] = 1;
    }
    warshall_floyd(G);
    int ans = 0;
    REP(i, N)REP(j, N) {
        if(INF != G[i][j])
            ans = max(ans, G[i][j]);
    }
    cout << ans + 1 << endl;
}