#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int A, B;
    cin >> A >> B;
    if(0 < A && B == 0) {
        cout << "Gold" << endl;
    } else if(A == 0 && 0 < B) {
        cout << "Silver" << endl;
    } else {
        cout << "Alloy" << endl;
    }
}