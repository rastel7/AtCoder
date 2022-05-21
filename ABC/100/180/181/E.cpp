#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N), W(M);
    REP(i, N) cin >> H[i];
    REP(j, M) cin >> W[j];
    W.emplace_back(-1e9);
    W.emplace_back(1e9);
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());
    vector<ll> WaL(N + 2), WaR(N + 2);
    REP(i, N) {
        WaL[i + 2] = WaL[i] + abs(H[i] - H[i + 1]);
        WaL[i + 1] = WaL[i];
        WaR[N + 1 - (i + 2)] = WaR[N+1-i] + abs(H[N-1 - i] - H[N-1 - (i + 1)]);
        WaR[N + 1 - (i + 1)] = WaR[N+1-i];
        i++;
    }
    ll ans = 1e18;
    for(int i = 0; i < N; i += 2) {
        auto tmp = lower_bound(W.begin(), W.end(), H[i]);
        ll tmp1 = *tmp,tmp2= *(--tmp);
        ll t = min(abs(tmp1-H[i]),abs(tmp2-H[i]));
        ans = min<ll>(ans, t + WaL[i + 1] + WaR[i + 1]);
    }
    cout << ans << endl;
}