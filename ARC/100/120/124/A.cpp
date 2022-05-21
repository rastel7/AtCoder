#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, K;
    cin >> N >> K;
    vector<mint> A(N, K);
    while(K--) {
        char c;
        int k;
        cin >> c >> k, k--;
        if(c == 'L') {
            REP(i, k) {
                if(A[i] != 1)
                    A[i]--;
            }
            A[k] = 1;
        } else {
            for(int i = N - 1; i > k; --i) {
                if(A[i] != 1)
                    A[i]--;
            }
            A[k] = 1;
        }
    }
    mint ans = 1;
    REP(i, N) ans *= A[i];
    cout << ans.val() << endl;
}