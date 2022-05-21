#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> P(N);
    REP(i, N) cin >> P[i];
    int a = 0, b = 0, c = 0;
    REP(i, N) {
        if(P[i] <= A) {
            a++;
        } else if(P[i] > B) {
            c++;
        } else {
            b++;
        }
    }
    cout << min(a, min(b, c)) << endl;
}
