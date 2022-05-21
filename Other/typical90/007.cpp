#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    A.emplace_back(INF);
    A.emplace_back(-INF);
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;
    while(Q--) {
        ll a;
        cin >> a;
        auto itr = lower_bound(A.begin(), A.end(), a);
        int t1 = *(itr++), t2 = *(itr--), t3 = *(--itr);
        cout << min(abs(t1 - a), min(abs(t2 - a), abs(t3 - a))) << endl;
    }
}