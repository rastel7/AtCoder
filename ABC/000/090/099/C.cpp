#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int dp[100000 * 3];
int main() {
    int N;
    cin >> N;
    REP(i, 100000 * 3)dp[i] = INF;
    vector<int> table(0);
    table.push_back(1);
    int num = 6;
    while(num < 100000) {
        table.push_back(num);
        num *= 6;
    }
    num = 9;
    while(num < 100000) {
        table.push_back(num);
        num *= 9;
    }
    sort(table.begin(), table.end());
    dp[0] = 0;
    REP(i, N) {
        REP(j, table.size()) {
            dp[i + table[j]] = min(dp[i + table[j]], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;
}