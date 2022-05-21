#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    int ans = 0;
    while(A < B) {
        ans++;
        A *= K;
    }
    cout << ans << endl;
}