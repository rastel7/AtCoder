#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll N, P;
    cin >> N >> P;
    vector<ll> beki(N + 10);
    beki[0] = 1;
    REP(i, beki.size() - 1) { beki[i + 1] = (beki[i] * 10LL) % P; }
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    if(P == 2 || P == 5) {
        ll ans = 0;
        REP(i, N) if((S[i] - '0') % P == 0) ans += N - i;
        cout << ans << endl;
        return 0;
    }
    map<ll, ll> mp;
    ll sum = 0;
    mp[0]++;
    REP(i, S.size()) {
        sum += beki[i] * (ll)(S[i] - '0');
        sum %= P;
        mp[sum]++;
    }
    ll ans = 0;
    for(auto [l, r] : mp) {
        ans += r * (r - 1LL) / 2LL;
    }

    cout << ans << endl;
}