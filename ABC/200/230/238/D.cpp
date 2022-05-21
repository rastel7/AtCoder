#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        ll a, s;
        cin >> a >> s;
        ll ans = 0;
        REP(i, 61) {
            if((a >> i) & 1) {
                ans += (1ll << (i + 1));
            }
        }

        for(ll i = 60; i >= 0; i--) {
            if(((a >> i) & 1)) {
                continue;
            }
            ll tmp = 1ll << i;
            if(tmp + ans <= s) {
                ans += tmp;
            }
        }

        if(ans == s) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}