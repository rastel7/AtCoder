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
    map<ll, ll> mp;
    REP(i, N) {
        int a;
        cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for(auto &a : mp) {
        ans += a.first * a.second;
    }
    int Q;
    cin >> Q;
    while(Q--) {
        ll b, c;
        cin >> b >> c;
        if(mp.count(b)) {
            ans -= mp[b] * b;
            ans -= mp[c] * c;
            mp[c] += mp[b];
            ans += mp[c] * c;
            mp.erase(b);
        }
        cout << ans << endl;
    }
}