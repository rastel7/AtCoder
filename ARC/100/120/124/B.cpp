#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
bool same(vector<ll> const &A, vector<ll> const &B) {
    REP(i, A.size()) {
        if(A[i] != B[i])
            return 0;
    }
    return 1;
}
int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    vector<ll> X(N);
    REP(i, N) X[i] = A[0] ^ B[i];
    sort(B.begin(), B.end());
    set<ll> ans;
    for(int i = 0; i < N; ++i) {
        vector<ll> C(N);
        REP(j, N) { C[j] = X[i] ^ A[j]; }
        sort(C.begin(), C.end());
        if(same(B, C)) {
            ans.insert(X[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto &i : ans) {
        cout << i << endl;
    }
}