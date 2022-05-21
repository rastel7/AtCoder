#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int n, k;
vector<P> A;
bool f(double x) {
    vector<double> tmp;
    REP(i, n) {
        tmp.push_back((A[i].second - x) * A[i].first);
    }
    sort(tmp.begin(), tmp.end(), greater<>());
    double sum = 0;
    REP(i, k) {
        sum += tmp[i];
    }
    return sum >= 0;
}
int main() {
    cin >> n >> k;
    A = vector<P>(n);
    REP(i, n)cin >> A[i].first >> A[i].second;
    double l = 0.0, r = 1e9;
    while(r - l > 1e-10) {
        double mid = l + (r - l) / 2.0;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << (l) << endl;
}