#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    ll N, K;
    cin >> N >> K;
    while(K != 0) {
        if(N % 200 == 0)
            N /= 200;
        else {
            N = N * 1000 + 200;
        }
        //cout << N << endl;
        K--;
    }
    cout << N << endl;
}