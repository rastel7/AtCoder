#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const int siz = 3010;
double dp[siz][siz];
int main() {
    int N;
    cin >> N;
    dp[0][0] = 1;
    for(int i = 0;i < N;++i) {
        double p;
        cin >> p;
        REP(j, N + 1) {
            dp[i + 1][j + 1] += p * dp[i][j];
            dp[i + 1][j] += (1 - p) * dp[i][j];
        }
    }
    double sm = 0;
    for(int i = (N + 1) / 2;i <= N;++i) {
        sm += dp[N][i];
    }
    cout << fixed << setprecision(10) << sm << endl;
}