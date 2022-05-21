#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
    if(a == 0)
        return 1;
    if(a == 1)
        return n % mod;
    if(a % 2 == 1)
        return (n * longpow(n, a - 1, mod)) % mod;
    ll t = longpow(n, a / 2, mod) % mod;
    return (t * t) % mod;
}
int main() {
    int a;
    cin >> a;
    cout << 3 * a * a << endl;
}