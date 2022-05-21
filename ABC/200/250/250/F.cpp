#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
struct P {
    ll x, y;
};
P operator-(const P &a1, const P &a2) { return P{a1.x - a2.x, a1.y - a2.y}; }
P operator+(const P &a1, const P &a2) { return P{a1.x + a2.x, a1.y + a2.y}; }
ll cross(P l, P r) { return l.x * r.y - l.y * r.x; }
vector<ll> X, Y;
int main() {
    ll N;
    cin >> N;
    X.resize(N), Y.resize(N);
    REP(i, N) { cin >> X[i] >> Y[i]; }
    vector<P> p(N);
    REP(i, N) p[i] = {X[i], Y[i]};
    ll s = 0;
    for(ll i = 2; i < N; ++i) {
        s += abs(cross(p[i - 1] - p[0], p[i] - p[0]));
    }
    ll res = 8e18, e = 0;
    int q = 1;
    REP(i, N) {
        while(e * 4 < s) {
            e += abs(cross(p[q] - p[i], p[(q + 1) % N] - p[i]));
            q++;
            q %= N;
            res = min(res, abs(4 * e - s));
        }
        e -= abs(cross(p[i] - p[q], p[(i + 1) % N] - p[q]));
        res = min(res, abs(4 * e - s));
    }
    cout << res << endl;
}