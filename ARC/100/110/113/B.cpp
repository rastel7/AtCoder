#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
    if(a == 0) return 1;
    if(a == 1) return n % mod;
    if(a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
    ll t = longpow(n, a / 2, mod) % mod;
    return (t * t) % mod;
}
int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    ll roop = 1;
    ll num = A % 10;
    while(true) {
        num %= 10;
        num *= (A % 10);
        num %= 10;
        if(num == A % 10) {
            break;
        } else {
            roop++;
        }

    }
    ll beki = longpow(B, C, roop);
    beki += roop;
    ll ans = longpow(A, beki, 10);
    cout << ans << endl;
}