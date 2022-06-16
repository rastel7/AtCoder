#include <atcoder/all>
#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using dsu = atcoder::dsu;
struct Edge {
    ll a, b, c, id;
};
bool operator<(const Edge &l, const Edge &r) { return l.c > r.c; }
int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> G(M);
    vector<vector<Edge>> G2(N);
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c, a--, b--;
        G[i] = {a, b, c, i + 1};
        G2[a].emplace_back(Edge{a, b, c, i + 1});
        G2[b].emplace_back(Edge{b, a, c, i + 1});
    }
    sort(G.begin(), G.end(), [&](Edge l, Edge r) { return l.c < r.c; });
    auto f = [](Edge l, Edge r) { return l.c < r.c; };
    priority_queue<Edge> queue;
    for(auto e : G2[0]) {
        queue.push(e);
    }
    dsu uf(N + 1);
    vector<ll> ans;
    const ll INF = 1e16;
    vector<ll> dist(N, 1e16);
    dist[0] = 0;
    while(!queue.empty()) {
        auto e = queue.top();
        queue.pop();
        if(uf.same(e.a, e.b))
            continue;
        uf.merge(e.a, e.b);
        ans.emplace_back(e.id);
        auto add = [&](int id) {
            for(auto next : G2[id]) {
                auto cost = dist[id] + next.c;
                auto nextedge = Edge{next.a, next.b, cost, next.id};
                queue.push(nextedge);
            }
        };
        if(dist[e.a] == INF) {
            dist[e.a] = e.c;
            add(e.a);
        } else {
            dist[e.b] = e.c;
            add(e.b);
        }
    }

    /*    for(auto g : G) {
        auto [a, b, c, id] = g;
        if(uf.same(a, b))
            continue;
        ans.emplace_back(id);
        uf.merge(a, b);
    }*/

    REP(i, ans.size()) {
        cout << ans[i];
        if(i + 1 != ans.size()) {
            cout << " ";
        }
    }
    cout << endl;
}