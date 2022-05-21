#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int C[100000 + 10];
set<int> s;
int color[100000 + 10];
void dfs(int id, int prev, vector<vector<int>> const &G) {
    color[C[id]]++;
    if(color[C[id]] == 1)
        s.insert(id);
    for(auto &a : G[id]) {
        if(a == prev) {
            continue;
        }

        dfs(a, id, G);
    }
    color[C[id]]--;
    return;
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    REP(i, N) { cin >> C[i]; }
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b, a--, b--;
        A[a].push_back(b), A[b].push_back(a);
    }
    set<int> past;
    dfs(0, -1, A);
    for(auto &i : s) {
        cout << i + 1 << endl;
    }
}