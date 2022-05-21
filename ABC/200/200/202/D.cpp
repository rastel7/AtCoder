#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
map<ll, ll> prime_factorization(long long n) {
    // map<ll,ll> first=素因数 second=first素因数の数
    map<ll, ll> res;
    for(int i = 2; i <= n / i; i++) {
        while(n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if(n != 1)
        res[n]++;
    return res;
}
ll C(ll n, ll r) {
    map<ll, int> bunbo, bunsi;
    for(int i = 0; i < r; ++i) {
        auto tmp = prime_factorization(i + 1);
        for(auto &a : tmp) {
            bunbo[a.first] += a.second;
        }
        tmp = prime_factorization(n - i);
        for(auto &a : tmp) {
            bunsi[a.first] += a.second;
        }
    }
    for(auto &a : bunsi) {
        int tmp = min(a.second, bunbo[a.first]);
        a.second -= tmp;
        bunbo[a.first] -= tmp;
    }
    ll ret = 1;
    for(auto &a : bunsi) {
        REP(i, a.second) ret *= a.first;
    }
    for(auto &b : bunbo) {
        REP(i, b.second) ret /= b.first;
    }
    return ret;
}
int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    ll sm = A + B;
    string ans = "";
    for(int i = 0; i < sm; ++i) {
        if(A == 0) {
            ans += 'b';
            continue;
        }
        ll tmp = C(A + B - 1, B);
        if(tmp < K) {
            ans += 'b';
            K -= C(A + B - 1, B);
            B--;
        } else {
            ans += 'a';

            A--;
        }
    }
    cout << ans << endl;
}