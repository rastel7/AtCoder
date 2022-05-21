#include <atcoder/all>
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
int main() {
    int n;
    cin >> n;
    int zero = 0;
    map<pair<ll, ll>, pair<ll, ll>> mp;
    REP(i, n) {
        ll x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) {
            zero++;
            continue;
        }
        ll g = __gcd(x, y);
        x /= g, y /= g;
        if(y < 0)
            x = -x, y = -y;
        if(y == 0 && x < 0) {
            x = -x, y = -y;
        }
        bool rot90 = (x <= 0);
        if(rot90) {
            ll tmp = x;
            x = y, y = -tmp;
        }
        if(rot90)
            mp[{x, y}].first++;
        else
            mp[{x, y}].second++;
    }

    mint ans = 1;
    for(auto p : mp) {
        int s = p.second.first, t = p.second.second;
        mint now = 1;
        now += mint(2).pow(s) - 1;
        now += mint(2).pow(t) - 1;
        ans *= now;
    }
    ans -= 1;
    ans += zero;
    cout << ans.val() << endl;
}