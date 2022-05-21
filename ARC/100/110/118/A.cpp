#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll t, N;
    cin >> t >> N;
    ll P = 100 + t;
    vector<ll> A(P, 1);
    REP(x, 100) A[P * x / 100] = 0;
    vector<ll> B;
    REP(i, A.size()) {
        if(A[i] == 1)
            B.emplace_back(i);
    }
    int r = (N - 1) % t;
    ll q = (N - 1) / t;
    cout << P * q + B[r] << endl;
}
