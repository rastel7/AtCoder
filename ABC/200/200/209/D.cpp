#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int N, Q;
vector<vector<int>> A;
int col[(int)1e5 + 10];
void dfs(int prev, int id, int color) {
    col[id] = color;
    for(auto &i : A[id]) {
        if(i == prev)
            continue;
        dfs(id, i, color == 0 ? 1 : 0);
    }
    return;
}
int main() {
    cin >> N >> Q;
    A.resize(N);
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b,a--,b--;
        A[a].emplace_back(b);
        A[b].emplace_back(a);
    }
    dfs(-1, 0, 0);
    REP(i, Q) {
        int c, d;
        cin >> c >> d,c--,d--;
        if(col[c] != col[d]) {
            cout << "Road" << endl;
        } else {
            cout << "Town" << endl;
        }
    }
}