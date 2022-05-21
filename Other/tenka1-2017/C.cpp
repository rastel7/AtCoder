#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll N;
    cin >> N;
    for(ll h = 1; h <= 3500; ++h) {
        for(ll n = 1; n <= 3500; ++n) {
            ll bunsi = N * n * h;
            ll bunbo = 4 * h * n - N * (n + h);
            if(bunbo <= 0)
                continue;
            if(bunsi % bunbo != 0)
                continue;
            cout << h << " " << n << " " << bunsi / bunbo << endl;
            return 0;
        }
    }
}