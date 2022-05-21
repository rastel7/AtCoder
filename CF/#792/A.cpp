#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int f(string s) {
    if(s.size() == 1) {
        return s[0] - '0';
    }
    if(s.size() == 2) {
        return s[1] - '0';
    }
    char c = s[0];
    REP(i, s.size()) { c = min(c, s[i]); }
    return c - '0';
}
void solve() {
    string n;
    cin >> n;
    cout << f(n) << endl;
}
int main() {
    int N;
    cin >> N;
    while(N--) {
        solve();
    }
}