#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int x, y;
    cin >> x >> y;
    if(x == y) {
        cout << x << endl;
    } else {
        cout << 3 - x - y << endl;
    }
}