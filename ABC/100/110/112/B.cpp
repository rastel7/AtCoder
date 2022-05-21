#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> C(n), T(n);
    REP(i, n)cin >> C[i] >> T[i];
    int ans = INF;
    REP(i, n) {
        if(t >= T[i]) {
            ans = min(ans, C[i]);
        }
    }
    if(ans == INF) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }
}