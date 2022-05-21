#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll N, A, B;
ll h[1001010];
bool f(ll x) {
    ll ret = 0;
    REP(i, N) {
        ll c = h[i] - x * B;
        if(c <= 0)continue;
        ret += (c + (A - B) - 1) / (A - B);
    }
    return ret <= x;
}
int main() {
    cin >> N >> A >> B;
    REP(i, N)cin >> h[i];
    ll l = -1, r = 1e9;
    while(r - l > 1) {
        ll mid = (l + r) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}