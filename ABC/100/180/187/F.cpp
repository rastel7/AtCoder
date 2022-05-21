#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const int INF = 1e6;
void chmin(int &a, int b) {
    if(a > b)
        a = b;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> g(N);
    while(M--) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        g[A] |= (1 << B);
        g[B] |= (1 << A);
    }
    vector dp(1 << N, INF);
    dp[0] = 1;
    REP(i, N) {
        for(int j = 0; j < (1 << N); ++j) {
            if(dp[j] == 1 && (g[i] & j) == j)
                dp[j | (1 << i)] = 1;
        }
    }
    for(int i = 1; i < (1 << N); ++i) {
        for(int j = i; --j &= i;) {
            chmin(dp[i], dp[i ^ j] + dp[j]);
        }
    }
    cout << dp.back() << endl;
}