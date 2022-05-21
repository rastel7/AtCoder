#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
void chmax(ll &a, ll b) { a = max(a, b); }
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) { cin >> A[i]; }
    static ll dp[201000][6];
    REP(i, 201000) REP(j, 3) dp[i][j] = -1e18;
    REP(i, 3) if(i < N) dp[i][i] = A[i];
    REP(i, N) REP(j, 3) {
        for(int d = 0; j + d < 3; ++d) {
            int bef = i - 2 - d;
            if(bef < 0)
                continue;
            chmax(dp[i][j + d], dp[bef][j] + A[i]);
        }
    }
    ll ans = -1e18;
    int D = 1 + N % 2;
    REP(d, D + 1) {
        int i = N - 1 - d;
        if(i >= 0)
            chmax(ans, dp[i][D - d]);
    }
    cout << ans << endl;
}