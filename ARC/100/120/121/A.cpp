#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A;
    REP(i, N) {
        int x, y;
        cin >> x >> y;
        A.emplace_back(vector<int>{x, y, (int)i});
    }
    set<P> s;
    sort(A.begin(), A.end());
    auto f = [&]() {
        s.insert(P(min(A[0][2], A[N - 1][2]), max(A[0][2], A[N - 1][2])));
        s.insert(P(min(A[1][2], A[N - 1][2]), max(A[1][2], A[N - 1][2])));
        s.insert(P(min(A[0][2], A[N - 2][2]), max(A[0][2], A[N - 2][2])));
        if(N != 3)
            s.insert(P(min(A[1][2], A[N - 2][2]), max(A[1][2], A[N - 2][2])));
    };
    f();
    REP(i, N) { swap(A[i][1], A[i][0]); }
    sort(A.begin(), A.end());
    f();
    REP(i, N) { swap(A[i][2], A[i][0]); }
    sort(A.begin(), A.end());
    vector<int> ans;
    for(auto &p : s) {
        int tmp = max(abs(A[p.first][1] - A[p.second][1]),
                      abs(A[p.first][2] - A[p.second][2]));
        ans.emplace_back(tmp);
    }
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 2] << endl;
}