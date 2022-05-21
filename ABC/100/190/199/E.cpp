#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M), Z(M);
    REP(i, M) cin >> X[i] >> Y[i] >> Z[i], Y[i]--;
    vector<ll> dp((1 << N) + 1);
    dp[0] = 1;
    
    REP(i, (1 << N)) {
        for(int x = 0; x < N; ++x) {
            if((i >> x) & 1)
                continue;
            int next = i | (1 << x);
            int bit_cnt = __builtin_popcountll(next);
            bool b = 1;
            REP(j, M) {
                if(X[j] == bit_cnt) {
                    int cnt = 0;
                    int id = 0, cpx = next;
                    while(id <= Y[j]) {
                        if((cpx >> id) & 1) {
                            cnt++;
                        }
                        id++;
                    }
                    if(cnt > Z[j])
                        b = 0;
                }
            }
            if(b)
                dp[next] += dp[i];
        }
    }
    cout << dp[(1 << N) - 1] << endl;
}