#include <atcoder/all>
#include <bits/stdc++.h>
using dsu = atcoder::dsu;
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
struct Edge {
    ll from, to, cost;
    ll query_id;
};
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<Edge> G(M + Q);
    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        G[i] = Edge{a-1, b-1, c, -1};
    }
    for(int i = M; i < M + Q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[i] = Edge{a-1, b-1, c, i - M + 1};
    }
    vector<int> add(Q);
    dsu uf(N);
    sort(G.begin(), G.end(), [](Edge l, Edge r) { return l.cost < r.cost; });
    for(auto e : G) {
        if(uf.same(e.from, e.to))
            continue;
        if(e.query_id == -1)
            uf.merge(e.from, e.to);
        else {
            add[e.query_id - 1] = 1;
        }
    }
    for(auto a : add) {
        if(a == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}