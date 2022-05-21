#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> C(N);
    REP(i, N) { cin >> C[i]; }
    map<ll, int> mp;
    REP(i, K) {
        int c = C[i];
        mp[c] = i;
    }
    int ans = mp.size();
    for(int i = K; i < N; ++i) {
        int id = i - K;
        if(mp[C[id]] == id) {
            mp.erase(C[id]);
        }
        mp[C[i]] = i;
        ans = max(ans, (int)mp.size());
    }
    cout << ans << endl;
}