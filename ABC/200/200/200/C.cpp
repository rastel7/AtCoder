#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    map<ll, ll> mp;
    REP(i, N) { mp[A[i] % 200]++; }
    ll ans = 0;
    for(auto &a : mp) {
        ans += (a.second - 1) * (a.second) / 2;
    }
    cout << ans << endl;
}