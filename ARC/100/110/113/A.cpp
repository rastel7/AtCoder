#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll K;
    cin >> K;
    ll ans = 0;
    for(ll i = 1;i <= K;++i) {
        ll num = K / i;
        ll cnt = 0;
        for(ll j = 1;j <= num;++j) {
            ll x = num / j;
            ans += x;
        }
    }
    cout << ans << endl;
}