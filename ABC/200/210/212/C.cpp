#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    REP(i, N) cin >> A[i];
    REP(i, M) cin >> B[i];
    B.emplace_back(-5e9), B.emplace_back(5e9);
    ll ans = 1e18;
    sort(B.begin(), B.end());
    REP(i, N) {
        auto itr = lower_bound(B.begin(), B.end(), A[i]);
        ll b_0 = *(itr--), b_1 = *(itr);
        ans = min(ans,min(abs(A[i]-b_0),abs(A[i]-b_1)));
    }
    cout << ans << endl;
}