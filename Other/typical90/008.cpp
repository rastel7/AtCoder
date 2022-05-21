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
const int MAX_N = 1e5 + 1000;
mint dp[10][MAX_N];
const string atc = "atcoder";
int main() {
    int N;
    string S;
    cin >> N >> S;
    dp[0][0] = 1;
    for(int i = 0; i < N; ++i) {
        REP(j, atc.size()) {
            dp[j][i + 1] += dp[j][i];
            if(S[i] == atc[j]) {
                dp[j + 1][i + 1] += dp[j][i];
            }
        }
        dp[atc.size()][i + 1] += dp[atc.size()][i];
    }
    cout << dp[atc.size()][N].val() << endl;
}