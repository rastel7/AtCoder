#include<bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i, N) {
        ans += (i + 1) * (i + 2) / 2;
    }
    REP(i, N - 1) {
        ll l, r;
        cin >> l >> r;
        if(r<l){
            swap(l,r);
        }
        ans -= l * (N - r + 1);
    }
    cout << ans << endl;
}