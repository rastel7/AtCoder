#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
ll K, N, M;
const ll MAX_K = 1e5 + 100;
ll A[MAX_K];
bool f(ll x) {
    vector<ll> L, R;
    REP(i, K) {
        ll l = (M * A[i] - x + N - 1) / N, r = (M * A[i] + x) / N;
        L.emplace_back(l), R.emplace_back(r);
    }
    ll L_SUM = accumulate(L.begin(), L.end(), (ll)0),
       R_SUM = accumulate(R.begin(), R.end(), (ll)0);
    if(M < L_SUM || R_SUM < M)
        return false;
    return true;
}
int main() {
    cin >> K >> N >> M;
    REP(i, K) cin >> A[i];
    ll l = -1, r = 1e18;
    while(r - l > 1) {
        ll mid = l + (r - l) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    ll x = r;
    vector<ll> L, R;
    REP(i, K) {
        ll l = (M * A[i] - x + N - 1) / N, r = (M * A[i] + x) / N;
        L.emplace_back(l), R.emplace_back(r);
    }
    ll L_SUM = accumulate(L.begin(), L.end(), (ll)0),
       R_SUM = accumulate(R.begin(), R.end(), (ll)0);
    vector<ll> ans(K);
    REP(i, K) ans[i] = L[i];
    REP(i, K) {
        if(L_SUM < M) {
            ll diff = min<ll>(M - L_SUM, R[i] - ans[i]);
            L_SUM += diff;
            ans[i] += diff;
        }
    }
    REP(i, K) {
        cout << ans[i];
        if(i != K - 1)
            cout << " ";
    }
    cout << endl;
}