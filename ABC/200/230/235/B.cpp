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
    ll i = 0;
    while(true) {
        if(i == N - 1)
            break;
        if(A[i] < A[i + 1]) {
            i++;
        } else {
            break;
        }
    }
    cout << A[i] << endl;
}