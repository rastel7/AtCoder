#include <atcoder/all>
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
const int SIZE = 2 * 1e3 + 100;
mint dp[SIZE][SIZE];
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    REP(i, N) cin >> A[i];
    REP(i, M) cin >> B[i];
    dp[0][0] = 1;
    REP(i, N + 1) REP(j, M + 1) {
        if(0 < i && 0 < j && A[i - 1] == B[j - 1]) {
            dp[i][j] += dp[i - 1][j - 1];
        }
        if(0 < i)
            dp[i][j] += dp[i - 1][j];
        if(0 < j)
            dp[i][j] += dp[i][j - 1];
        if(0 < i && 0 < j) {
            dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    cout << dp[N][M].val() << endl;
}