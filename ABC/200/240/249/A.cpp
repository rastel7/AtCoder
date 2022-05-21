#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    ll taka = 0, ao = 0;
    for(int i = 0; i < X; ++i) {
        ll time = i % (A + C);
        if(time < A) {
            taka += B;
        }
        time = i % (D + F);
        if(time < D) {
            ao += E;
        }
    }
    if(taka > ao) {
        cout << "Takahashi" << endl;
    } else if(taka < ao) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}