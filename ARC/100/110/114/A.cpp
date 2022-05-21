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
// 返り値: a と b の最大公約数
template <typename T> ll gcd(T a, T b) {
    if(b == 0) {
        return a;
    }
    ll d = gcd(b, a % b);
    return d;
}
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> prime;
    for(int i = 2; i <= 50; ++i) {
        auto mp = prime_factorization(i);
        if(mp.size() == 1) {
            auto t = *mp.begin();
            if(t.second == 1) {
                prime.emplace_back(i);
            }
        }
    }
    ll ans = INF;
    for(int i = 1; i < (1 << prime.size()); ++i) {
        ll tmp = i, id = 0, t1 = 1;
        while(tmp != 0) {
            if(tmp & 1)
                t1 *= prime[id];
            tmp = tmp >> 1, id++;
        }

        bool b = 1;
        for(auto &a : A) {
            if(gcd(a, t1) == 1)
                b = 0;
        }
        if(b)
            ans = min(ans, t1);
    }
    cout << ans << endl;
}