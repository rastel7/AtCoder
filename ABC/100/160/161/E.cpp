#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<ll> L(K), R(K);
    int j = 0;
    REP(i, N) {
        if(j == K)
            break;
        if(S[i] == 'x')
            continue;
        L[j] = (i);
        i += C, ++j;
    }
    j = K - 1;
    for(ll i = N - 1; i >= 0; i--) {
        if(j < 0)
            break;
        if(S[i] == 'x')
            continue;
        R[j] = i;
        i -= C, --j;
    }
    REP(i, K) {
        if(L[i] == R[i]) {
            cout << L[i] + 1 << endl;
        }
    }
}
