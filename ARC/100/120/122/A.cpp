#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
mint dp[100000 + 100][2];
int main() {
    int N;
    cin >> N;
    vector<mint> A(N);
    REP(i, N) {
        int a;
        cin >> a;
        A[i] = a;
    }
    dp[0][1] = 1, dp[0][0] = 1;
    REP(i, N) {
        dp[i + 1][0] = dp[i][1];
        dp[i + 1][1] = dp[i][1] + dp[i][0];
    }
    mint ans = 0;
    ans += A[0] * dp[N - 1][1];
    for(int i = 1; i < N; ++i) {
        ans += A[i] * dp[i - 1][1] * dp[N - 1 - i][1];
        ans += A[i] * dp[i - 1][0] * dp[N - 1 - i][0] * -1;
    }
    cout << ans.val() << endl;
}