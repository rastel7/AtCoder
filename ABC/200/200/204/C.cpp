#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
vector<vector<int>> A;
set<int> s;
void dfs(int id) {
    s.insert(id);
    for(auto &a : A[id]) {
        if(!s.count(a))
            dfs(a);
    }
}
int main() {

    int N, M;
    cin >> N >> M;
    A.resize(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b, a--, b--;
        A[a].emplace_back(b);
    }
    int ans = 0;
    REP(i, N) {
        dfs(i);
        ans += s.size();
        s.clear();
    }
    cout << ans << endl;
}