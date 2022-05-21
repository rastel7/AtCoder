#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll R, X, Y;
    cin >> R >> X >> Y;
    if(X * X + Y * Y < R*R) {
        cout << 2 << endl;
        return 0;
    }
    ll tmp = (X * X + Y * Y - 1 + R * R) / (R * R);
    for(ll i = 1;; ++i) {
        if(i * i >= tmp) {
            cout << i << endl;
            return 0;
        }
    }
}