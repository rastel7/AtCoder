#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
ll N, K;
ll A[201010];
ll get_minus(ll lim) {
    vector<ll> mi, pl;
    REP(i, N) {
        if(A[i] < 0)
            mi.push_back(A[i]);
        if(A[i] > 0)
            pl.push_back(A[i]);
    }
    ll j = 0;
    ll res = 0;
    for(auto m : mi) {
        while(j < pl.size() && lim < m * pl[j])
            ++j;
        res += pl.size() - j;
    }
    return res;
}
ll get_zero() {
    ll zero = 0;
    REP(i, N) if(A[i] == 0) zero++;
    return 1LL * zero * (N - zero) + zero * (zero - 1) / 2;
}
ll get_plus(ll lim) {
    vector<ll> mi, pi;
    REP(i, N) if(0 < A[i]) pi.emplace_back(A[i]);
    REP(i, N) if(A[N - 1 - i] < 0) mi.emplace_back(A[N - 1 - i]);
    ll res = 0;
    ll n = mi.size();
    ll j = n - 1;
    REP(i, n) {
        while(i < j && lim < mi[i] * mi[j])
            j--;
        res += max(0LL, j - i);
    }
    n = pi.size();
    j = n - 1;
    REP(i, n) {
        while(i < j && lim < pi[i] * pi[j])
            j--;
        res += max(0LL, j - i);
    }
    return res;
}
ll get_count(ll lim) {
    ll res = get_minus(min(lim, -1LL));
    if(0 <= lim)
        res += get_zero();
    if(0 < lim)
        res += get_plus(lim);
    return res;
}
int main() {
    cin >> N >> K;
    REP(i, N) cin >> A[i];
    sort(A, A + N);
    ll l = LONG_LONG_MIN, r = LONG_LONG_MAX;
    while(l + 1 != r) {
        ll md = (l + r) / 2;
        if(K <= get_count(md))
            r = md;
        else
            l = md;
    }
    cout << r << endl;
}