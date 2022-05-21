#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll my_pow(ll x, ll k) {
    REP(i, k - 1) x *= x;
    return x;
}
void solve() {
    ll N;
    cin >> N;
    if(N == 1) {
        cout << 0 << endl;
        return;
    }
    if(N % 2 == 1) {
        cout << 1 << endl;
        return;
    }
    int cnt = 0;
    while(N % 2 == 0) {
        N /= 2;
        cnt++;
    }
    if(cnt % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    if(N == 1) {
        cout << 1 << endl;
    }
    REP(i, cnt) N *= 2;
    ll x = powl(N, 1.0 / (double)cnt) - 100;
    if(x < 0)
        x = 1;
    while(my_pow(x, cnt) < N) {
        x++;
    }
    if(my_pow(x, cnt) == N) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
}
int main() {
    ll T;
    cin >> T;
    while(T--) {
        solve();
    }
}