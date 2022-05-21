#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int N;
ll A[100000 + 1000];
double f(double x) {
    double ret = 0;
    REP(i, N) { ret += (x + A[i] - min<double>((double)A[i], 2 * x)) / N; }
    return ret;
}
int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    double l = 0, r = 1e18;
    while(r - l >= 1e-7) {
        double mid_l = l + (r - l) / 3, mid_r = l + (r - l) * 2 / 3;
        if(f(mid_l) < f(mid_r)) {
            r = mid_r;
        } else {
            l = mid_l;
        }
    }
    cout << fixed << setprecision(7) << f((l + r) / 2) << endl;
}