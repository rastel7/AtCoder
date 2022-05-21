#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int op(int l, int r) {
    return min(l, r);
}
int e() {
    return INF;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> Wa(n + 1);
    vector<int> X(m), Y(m);
    REP(i, m) {
        int s, t;
        cin >> s >> t, s--;
        X[i] = s + 1, Y[i] = t;
        Wa[s]++, Wa[t]--;
    }
    REP(i, n) {
        Wa[i + 1] += Wa[i];
    }
    segtree<int, op, e> seg(n + 2);
    REP(i, n + 1) {
        seg.set(i, Wa[i]);
    }
    vector<int> ans;
    REP(i, m) {
        if(seg.prod(X[i] - 1, Y[i]) > 1) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
}