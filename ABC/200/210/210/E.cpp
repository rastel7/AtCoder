#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
// 返り値: a と b の最大公約数
template <typename T> ll gcd(T a, T b) {
    if(b == 0) {
        return a;
    }
    ll d = gcd(b, a % b);
    return d;
}
int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> A(M);
    REP(i, M) cin >> A[i].second >> A[i].first;
    sort(A.begin(), A.end());
    ll ans = 0;
    vector<ll> X(M + 1);
    X[0] = N;
    REP(i, M) { X[i + 1] = gcd(X[i], A[i].second); }
    if(X.back() != 1) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, M) { ans += A[i].first * (X[i] - X[i + 1]); }
    cout << ans << endl;
}