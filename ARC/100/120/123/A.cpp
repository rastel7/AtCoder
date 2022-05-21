#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    vector<ll> A(3);
    REP(i, 3) cin >> A[i];
    auto B = A;
    sort(B.begin(), B.end());
    if(B[0] == B[1] && B[2] - B[1] == 1) {
        // cout << 2 << endl;
        // return 0;
    }
    ll ans = INF;
    ll a = A[1] * 2, b = A[0] + A[2];
    if(a < b) {
        ans = min(ans, (ll)(b - a + 1) / 2 + (b % 2 == 1 ? 1 : 0));
    } else {
        ans = min(ans, a - b);
    }
    cout << ans << endl;
}