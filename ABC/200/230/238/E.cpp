#include <atcoder/all>
#include <bits/stdc++.h>
using dsu = atcoder::dsu;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> l(Q), r(Q);
    dsu uf(N + 1);
    REP(i, Q) {
        cin >> l[i] >> r[i];
        uf.merge(l[i] - 1, r[i]);
    }
    if(uf.same(0, N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}