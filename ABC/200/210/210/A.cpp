#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, A, X, Y;
    cin >> N >> A >> X >> Y;
    if(N <= A) {
        cout << X * N << endl;
    } else {
        cout << X * A + Y * (N - A) << endl;
    }
}