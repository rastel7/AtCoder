#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll f(ll a, ll b) { return a * a * a + a * a * b + a * b * b + b * b * b; }
int main() {
    ll N;
    cin >> N;
    ll ans = 1e18;
    for(ll a = 0; a <= 1e6; ++a) {
        ll l = -1, r = 1e6 ;
        while(r - l > 1) {
            ll mid = l + (r - l) / 2;
            ll cnt = f(a, mid);
            if(cnt >= N) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans = min(ans, f(a, r));
    }
    cout << ans << endl;
}