#include <atcoder/all>
#include <bits/stdc++.h>
using mint = atcoder::modint998244353;
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
map<pair<int, int>, mint> dp;
ll N, M, K;
mint f(int rem_cnt, int rem_num) {
    if(dp.count({rem_cnt, rem_num})) {
        return dp[{rem_cnt, rem_num}];
    }
    if(rem_num < 0) {
        return 0;
    }
    if(rem_cnt == 0) {
        return 1;
    }
    if(rem_num <= 0) {
        return 0;
    }
    mint ret = 0;
    for(int i = 1; i <= M; ++i) {
        ret += f(rem_cnt - 1, rem_num - i);
    }
    return dp[{rem_cnt, rem_num}] = ret;
}
int main() {
    cin >> N >> M >> K;
    mint ans = f(N, K);
    cout << ans.val() << endl;
}