#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    if((V -W) * T >= abs(A - B)) {
        cout << "YES" << endl;

    } else {
        cout << "NO" << endl;
    }
}