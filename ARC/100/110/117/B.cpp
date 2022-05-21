#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
using mint = modint1000000007;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    sort(A.begin(), A.end(), greater<>());
    A.erase(unique(A.begin(), A.end()), A.end());
    mint ans(1);
    for(int i = 0; i < A.size() - 1; ++i) {
        ans *= A[i] - A[i + 1] + 1;
    }
    ans *= A[A.size() - 1] + 1;
    cout << ans.val() << endl;
}