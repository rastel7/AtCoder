#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> low(N);
    REP(i, N) { low[i] = A[i] - (i + 1); }
    while(Q--) {
        ll num;
        cin >> num;
        int id = (lower_bound(low.begin(), low.end(), num) - low.begin());
        if(id == N) {
            cout << A[N - 1] + num - low[N - 1] << endl;
        } else {
            cout << A[id] - (low[id] - num + 1) << endl;
        }
    }
}