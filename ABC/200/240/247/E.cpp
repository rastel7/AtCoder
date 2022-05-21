#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
vector<ll> A;
ll N, X, Y;
ll f(ll l, ll r) {
    if(l == r)
        return 0;
    vector<ll> mx, mn;
    for(int i = l; i < r; ++i) {
        if(A[i] == X) {
            mx.emplace_back(i);
        } else if(A[i] == Y) {
            mn.emplace_back(i);
        }
    }
    if(mx.empty() || mn.empty())
        return 0;

    ll prev = l, ret = 0;
    ;
    reverse(mx.begin(), mx.end());
    for(auto x : mn) {
        ll l_diff = x - prev;
        auto itr = upper_bound(mx.begin(), mx.end(), x);
        if(itr == mx.end())
            continue;
        ll r_diff = r - *itr;
        ret += l_diff * r_diff;
    }
    return ret;
}
int main() {
    cin >> N >> X >> Y;
    A.resize(N);
    REP(i, N) cin >> A[i];
    vector<ll> high, low, out;
    REP(i, N) {
        if(A[i] == Y) {
            low.emplace_back(i);
        }
        if(A[i] == X) {
            high.emplace_back(i);
        }
        if(A[i] < Y || X < A[i]) {
            out.emplace_back(i);
        }
    }
    ll ans = 0;
    REP(i, N) {
        auto l_near = lower_bound(low.begin(), low.end(), i);
        auto r_near = lower_bound(high.begin(), high.end(), i);
        if(l_near == low.end() || r_near == high.end())
            continue;
        ll r = max(*l_near, *r_near);
        auto ng_near = lower_bound(out.begin(), out.end(), i);
        ll ng;
        if(ng_near == out.end()) {
            ng = N;
        } else {
            ng = *ng_near;
        }

        ans += max(0ll, (ng - r));
    }
    cout << ans << endl;
}