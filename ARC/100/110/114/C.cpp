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
int main() {
    int n, m;
    cin >> n >> m;
    mint ans = 0;
    if(n == 1) {
        cout << m << endl;
        return 0;
    }
    ans = m * (2 * m - 1);
    cout << ans.val() << endl;
    for(int _cnt = 3;_cnt <= n;++_cnt) {
        mint tmp = mint(_cnt).pow(m);
        tmp = tmp * (m - 1) / m;
        ans *= tmp;
        cout << ans.val() << endl;
    }
    cout << ans.val() << endl;
}