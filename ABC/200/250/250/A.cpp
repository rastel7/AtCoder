#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll H, W, R, C;
    cin >> H >> W >> R >> C;
    ll ans = 0;
    for(int a = 1; a <= H; ++a) {
        for(int b = 1; b <= W; ++b) {
            if(abs(a - R) + abs(b - C) <= 1)
                ans++;
        }
    }
    cout << ans-1 << endl;
}