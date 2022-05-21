#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll add = 0;
pair<ll, ll> f(long double x, vector<ll> A) {
    int N = A.size();
    long double s0, t0, s1, t1;
    s0 = add, t0 = 0;
    for(int i = 1; i < N; ++i) {
        s1 = t0;
        t1 = max(s0, t0) + A[i];
        s0 = s1, t0 = t1;
    }
    return {s0, t0};
}
const int SIZE = 1e6;
ll dp[2][SIZE];
int main() {
    const ll INF = 1e17;
    auto res = [&]() {
        REP(i, SIZE) { dp[0][i] = dp[1][i] = INF; }
    };
    res();
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    //１使う
    dp[1][0] = A[0];
    //dp[0][0] = 0;
    for(int i = 1; i < N; ++i) {
        dp[1][i] = min(dp[0][i - 1] + A[i], dp[1][i - 1] + A[i]);
        dp[0][i] = dp[1][i - 1];
    }
    ll ans = min(dp[0][N - 1], dp[1][N - 1]);
    res();
    
        //１わない
    dp[0][0] = 0;
    for(int i = 1; i < N; ++i) {
        dp[1][i] = min(dp[0][i - 1] + A[i], dp[1][i - 1] + A[i]);
        dp[0][i] = dp[1][i - 1];
    }
  
    ans = min(ans, dp[1][N - 1]);
    cout << ans << endl;
}