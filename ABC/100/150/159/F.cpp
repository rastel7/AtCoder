#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
using mint = atcoder::modint998244353;
mint dp[3010][6010][3];
int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    dp[0][0][0] = 1;
    REP(i, N) {
        REP(sum, S + 1) {
            REP(state, 3) {
                REP(next, 3) {
                    if(next < state)
                        continue;
                    dp[i + 1][sum][next] += dp[i][sum][state];
                    if(next != 0 && state != 2) {
                        dp[i + 1][sum + A[i]][next] += dp[i][sum][state];
                    }
                }
            }
        }
    }
    cout << dp[N][S][2].val() << endl;
}