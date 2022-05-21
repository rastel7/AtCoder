#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
using mint = modint998244353;
mint dp[4000][4000];
int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    REP(i, C - A + 1) {
        REP(j, D - B + 1) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i == 0) {
                dp[i][j] = dp[i][j - 1] * A;
                continue;
            }
            if(j == 0) {
                dp[i][j] = dp[i - 1][j] * B;
                continue;
            }
            dp[i][j] = (dp[i][j - 1] * (i + A) + dp[i - 1][j] * (j + B) - dp[i - 1][j - 1] * (j + B - 1) * (i + A - 1));
        }
    }
    cout << dp[C - A][D - B].val() << endl;
}