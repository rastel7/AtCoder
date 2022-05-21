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
    vector<string> s(N);
    vector<int> t(N);
    REP(i, N) { cin >> s[i] >> t[i]; }
    string x;
    cin >> x;
    int i = 0;
    for(; i < N; ++i) {
        if(s[i] == x)
            break;
    }
    i++;
    int ans = 0;
    for(; i < N; ++i) {
        ans += t[i];
    }
    cout << ans << endl;
}