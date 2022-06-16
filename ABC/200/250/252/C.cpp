#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) cin >> S[i];
    ll ans = 1e9;
    REP(target, 10) {
        set<ll> s;
        REP(i, N) {
            REP(j, S[i].size()) {
                if(S[i][j] - '0' == target) {
                    ll num = j;
                    while(s.count(num)) {
                        num += 10;
                    }
                    s.insert(num);
                }
            }
        }
        ll mx = 0;
        for(auto a : s) {
            mx = max(a, mx);
        }
        ans = min(mx, ans);
    }
    cout << ans << endl;
}