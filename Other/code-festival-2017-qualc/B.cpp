#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll dp[2][15];
int main() {
    REP(i, 2)REP(j, 15)dp[i][j] = 0;
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N)cin >> A[i];
    dp[1][0] = 1;
    REP(i, N) {
        if(A[i] % 2 == 0) {
            dp[0][i + 1] += dp[1][i];
            dp[1][i + 1] += 2 * dp[1][i];

        } else {
            dp[0][i + 1] += 2 * dp[1][i];
            dp[1][i + 1] += dp[1][i];
        }
        dp[0][i + 1] += 3 * dp[0][i];
    }
    cout << dp[0][N] << endl;
}