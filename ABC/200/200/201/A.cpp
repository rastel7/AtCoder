#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    vector<int> A(3);
    REP(i, 3) cin >> A[i];
    sort(A.begin(), A.end());
    if(A[1] - A[0] == A[2] - A[1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}