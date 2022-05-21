#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
using mint = modint1000000007;
const int INF = 1e9;
const ll MOD = 1000000007;
const int siz = 2 * 100000 + 1000;
mint dp[siz];
int prev_c[siz];
int main() {
    int N, _N;
    cin >> N;
    _N = N;
    REP(i, siz) {
        prev_c[i] = -1;
        dp[i] = 0;
    }
    dp[0] = 1;
    int id = 0;
    while(N--) {
        int c;
        cin >> c;

        dp[id + 1] += dp[id];
        if(prev_c[c] == -1 || prev_c[c] == id - 1) {

        } else {
            dp[id + 1] += dp[prev_c[c]+1];
        }
        prev_c[c] = id;
        id++;
    }
    cout << dp[_N].val() << endl;
}