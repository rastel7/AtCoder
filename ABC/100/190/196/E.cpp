#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
const ll INF = 1e15;
int main() {
    int N;
    cin >> N;
    vector<int> a(N), t(N);
    REP(i, N)cin >> a[i] >> t[i];
    ll A, B, C;
    auto f = [&](ll x) {
        return min<ll>(A, max<ll>(B, C + x));
    };
    if(t[0] == 1) {
        A = INF, B = -INF, C = a[0];
    }
    if(t[0] == 2) {
        A = INF, B = a[0], C = 0;
    }
    if(t[0] == 3) {
        A = a[0], B = -INF, C = 0;
    }
    for(int i = 1;i < N;++i) {
        ll a1, b1, c1;
        if(t[i] == 1) {
            a1 = INF, b1 = -INF, c1 = a[i];
        }
        if(t[i] == 2) {
            a1 = INF, b1 = a[i], c1 = 0;
        }
        if(t[i] == 3) {
            a1 = a[i], b1 = -INF, c1 = 0;
        }
        ll ta, tb, tc;
        ta = min(a1, max(b1,A + c1));
        tb = max(b1, B + c1);
        tc = C + c1;
        A = ta, B = tb, C = tc;
    }
    int Q;
    cin >> Q;
    REP(i, Q) {
        int x;
        cin >> x;
        cout << f(x) << endl;
    }
}