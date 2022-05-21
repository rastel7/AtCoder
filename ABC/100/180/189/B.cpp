#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll N, X;
    cin >> N >> X, X *= 100;
    vector<ll> V(N), P(N);
    REP(i, N)cin >> V[i] >> P[i], V[i] *= P[i];
    ll now = 0;
    REP(i, N) {
        now += V[i];
        if (now > X) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    if (now > X) {
        cout << N << endl;
    } else {
        cout << -1 << endl;
    }
}