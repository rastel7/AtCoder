#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<ll> eratosthenes(int n) {
    vector<ll> ret;
    vector<bool> isPrime(n + 1, 1);
    for(ll i = 2; i <= n; ++i) {
        if(!isPrime[i])
            continue;
        ret.emplace_back(i);
        for(ll j = 2; i <= n / j; ++j) {
            isPrime[j * i] = 0;
        }
    }
    return ret;
}
int main() {
    ll N;
    cin >> N;
    ll mx = min<ll>(1e6+1, N + 100);
    auto erato = eratosthenes(mx);
    ll ans = 0;
    for(ll p = 0; p < erato.size(); ++p) {
        ll pn = erato[p];
        for(ll q = p + 1; q < erato.size(); ++q) {
            ll qn = erato[q];
            long double tmp = 0;
            tmp = (long double)pn * (long double)qn * (long double)qn *
                  (long double)qn;
            if(tmp > N + 100)
                break;
            ll num = pn * qn * qn * qn;
            if(num <= N)
                ans++;
            else
                break;
        }
    }
    // for(auto c : s)
    //     cout << c << endl;
    cout << ans << endl;
}