#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
void merge(map<int, int> &l, map<int, int> const &r) {
    for(auto &i : r) {
        l[i.first] += i.second;
    }
}
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    REP(i, N) cin >> C[i];
    vector<map<int, int>> M(N + 1);
    REP(i, N) M[i + 1][C[i]]++;
    dsu uf(N + 1);
    while(Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            if(uf.same(b, c))
                continue;
            int b_leader = uf.leader(b);
            int c_leader = uf.leader(c);
            uf.merge(b, c);
            if(uf.leader(b) == b_leader) {
                merge(M[uf.leader(b)], M[c_leader]);
            } else {
                merge(M[uf.leader(c)], M[b_leader]);
            }

        } else {
            cout << M[uf.leader(b)][c] << endl;
        }
    }
}