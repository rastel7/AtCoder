#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const int MAX_N = 1200000 ;
ll dp[4][MAX_N * 4];
int main() {
    ll N, K;
    cin >> N >> K;
    dp[0][0] = 1;
    REP(i, 3) {
        REP(j, N * i + 1) {
            dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j + N + 1] -= dp[i][j];
        }
        REP(j, N * (i + 1)+1) {
            dp[i + 1][j + 1] += dp[i + 1][j];
        }
    }
    int x;
    for(int i = 3;i <= 3 * N;++i) {
        if(K <= dp[3][i]) {
            x = i;
            break;
        } else {
            K -= dp[3][i];
        }
    }
    for(int i = 1;i <= N;++i) {
        ll jmi = max<ll>(1, x - i - N);
        ll jma = min<ll>(N, x - i - 1);
        if(jmi > jma)continue;
        if(K > (jma - jmi + 1)) {
            K -= (jma - jmi + 1);
            continue;
        }
        ll y = jmi + K - 1;
        ll z = x - i - y;
        cout << i << " " << y << " " << z << endl;
        return 0;
    }
}