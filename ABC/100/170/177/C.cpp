#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<mint> A(N);
    REP(i, N) {
        int a;
        cin >> a;
        A[i] = a;
    }
    mint sum = 0;
    REP(i, N) sum += A[i];
    mint ans = 0;
    for(int i = 0; i < N - 1; ++i) {
        sum -= A[i];
        ans += sum * A[i];
    }
    cout << ans.val() << endl;
}