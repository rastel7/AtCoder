#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using namespace atcoder;
void solve() {
    ll X, Y, P, Q;
    cin >> X >> Y >> P >> Q;
    ll ans = LONG_LONG_MAX;
    for(ll t1 = X;t1 < X + Y;++t1) {
        for(ll t2 = P;t2 < P + Q;++t2) {
            auto c = crt({ t1,t2 }, { (X + Y) * 2,P + Q });
            if(c.second == 0)continue;
            cerr << c.second << endl;
            ans = min(ans, c.first);
        }
    }
    if(ans != LONG_LONG_MAX)
        cout << ans << endl;
    else
        cout << "infinity" << endl;
}
int main() {
    ll T;
    cin >> T;
    while(T--) {
        solve();
    }
}