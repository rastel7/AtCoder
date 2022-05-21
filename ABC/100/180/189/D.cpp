#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll dp[100][2];
int main()
{
    int n;
    cin >> n;
    vector<string> S(n);
    REP(i, n)
    cin >> S[i];
    REP(i, 100)
    REP(j, 2)
    dp[i][j] = 0;
    dp[0][0] = 1, dp[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (S[i - 1] == "AND")
        {
            dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 2;
        }
    }
    cout << dp[n][1] << endl;
}