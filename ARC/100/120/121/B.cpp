#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
const int MAX_N = 2e5 + 100;
ll dp[MAX_N][2][2][2][2];
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
int main() {
    int N;
    cin >> N;
    REP(i, MAX_N)
    REP(j, 2) REP(k, 2) REP(l, 2) REP(m, 2) dp[i][j][k][l][m] = INF;
    vector<pair<ll,char>> A(N*2);
    REP(i, N * 2) { cin >> A[i].first >> A[i].second; }
    sort(A.begin(), A.end());
    dp[0][0][0][0][0] = 0;
    REP(i, N * 2) {
        REP(j, 2) REP(k, 2) REP(l, 2) {
            switch(A[i].second) {
            case 'R':
                chmin(dp[i + 1][0][j][k][l], dp[i][1][j][k][l]);
                chmin(dp[i + 1][1][j][k][l], dp[i][0][j][k][l]);
                break;
            case 'G':
                chmin(dp[i + 1][j][1][k][l], dp[i][j][0][k][l]);
                chmin(dp[i + 1][j][0][k][l], dp[i][j][1][k][l]);
                break;

            case 'B':
                chmin(dp[i + 1][k][j][0][l], dp[i][k][j][1][l]);
                chmin(dp[i + 1][k][j][1][l], dp[i][k][j][0][l]);
                break;
            default:
                break;
            }
            chmin(dp[i + 1][j][k][l][0], dp[i][j][k][l][1] + A[i].first);
            chmin(dp[i + 1][j][k][l][1], dp[i][j][k][l][0] - A[i].first);
        }
    }
    cout << dp[N * 2][0][0][0][0] << endl;
}