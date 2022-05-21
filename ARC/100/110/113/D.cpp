#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
using mint = modint998244353;
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    if(n == 1 || m == 1) {
        cout << mint(k).pow(max(n, m)).val() << endl;
        return 0;
    }
    mint ans = 0;
    for(int i = 1;i <= k;++i) {
        ans += (mint(i).pow(n) - mint(i - 1).pow(n)) * (mint(k - i + 1).pow(m));
    }
    cout << ans.val() << endl;
}