#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll OFS = 10000;
ll my_round(ll x, ll r) {
    ll tmp = x - r;
    if(tmp < 0) {
        return (tmp / OFS) * OFS;
    } else {
        return ((tmp+OFS-1) / OFS) * OFS;
    }
    ll start = x - r;
    if(start % OFS != 0) {
        start += OFS - (start + (ll)1e10) % OFS;
    }
    return start;
}
ll my_round1(ll x) {
    //0方向へ丸める
    if(x > 0) {
        //cerr << x << " " << (x / OFS) * OFS << endl;
        return (x / OFS);
    }
    return ((x - OFS + 1) / OFS);
}
ll my_round2(ll x) {
    //無限方向へ丸める
    if(x > 0) {
        //cerr << x << " " << (x / OFS) * OFS << endl;
        return ((x + OFS - 1) / OFS);
    }
    return (x / OFS);
}
ll my_sqrt(ll x) {

    ll l = 0, r = 2e9;
    while(r - l > 1) {
        ll mid = (l + r) / 2;
        if(mid * mid <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    //cerr << x << " " << l << endl;
    return l;
}
int main() {
    long double X, Y, R;
    cin >> X >> Y >> R, R += 1e-15;;
    ll x, y, r;
    x = round(X * OFS), y = round(Y * OFS), r = round(R * OFS);
    ll ans = 0;
    for(ll y_0 = my_round(y, r);y_0 <= y + r;y_0 += OFS) {
        ll x_1 = my_round1(x + my_sqrt(r * r - (y - y_0) * (y - y_0)));
        ll x_0 = my_round2(x - my_sqrt(r * r - (y - y_0) * (y - y_0)));
        ans += (x_1 - x_0) + 1;
    }
    cout << ans << endl;
}