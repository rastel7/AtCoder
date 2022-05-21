#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int T;
    cin >> T;
    REP(t, T) {
        ll x, y;
        cin >> x >> y;
        string S;
        cin >> S;
        vector<vector<ll>> dp(S.size() + 1, vector<ll>(2, 0));
        REP(i, S.size()) {
            if(S[i] == 'C') {
                dp[i + 1][0] = min(dp[i][0], dp[i][1] + y);
                dp[i + 1][1] = INF;
                continue;
            }
            if(S[i] == 'J') {
                dp[i + 1][0] = INF;
                dp[i + 1][1] = min(dp[i][0] + x, dp[i][1]);
                continue;
            }
            dp[i + 1][0] = min(dp[i][0], dp[i][1] + y);
            dp[i + 1][1] = min(dp[i][0] + x, dp[i][1]);
        }
        printf("Case #%ld: %ld\n", t+1, min(dp[S.size()][0], dp[S.size()][1]));
    }
}