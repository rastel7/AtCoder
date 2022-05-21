#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int c(char c) {
    return c - '0';
}
int dp[2][1000000 + 100];
int main() {
    string S;
    cin >> S;
    dp[1][0] = 1;
    REP(i, S.size()) {
        int now = c(S[i]);
        dp[0][i + 1] = min(dp[0][i] + now, dp[1][i] + 10 - now);
        dp[1][i + 1] = min(dp[0][i] + now + 1, dp[1][i] + (10 - now - 1));
    }
    cout << dp[0][S.size()] << endl;
}