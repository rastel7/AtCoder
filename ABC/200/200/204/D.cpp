#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll dp[110][1100000];
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, 1e5 + 100) {
            dp[i + 1][j + A[i]] |= dp[i][j];
            dp[i + 1][j] |= dp[i][j];
        }
    }
    int sum = 0, tm;
    REP(i, N)sum += A[i];
    tm = sum;
    sum = (sum+1)/2;
    //cout << sum << endl;
    for(;;sum++) {
        if(dp[N][sum]) {
            cout << sum << endl;
            return 0;
        }
    }
}