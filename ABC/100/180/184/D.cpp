#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
const int MAX_N = 110;
bool dp[MAX_N][MAX_N][MAX_N];
map<tuple<int, int, int>, double> mp;
double f(int a, int b, int c) {
    if(a >= 100 || b >= 100 || c >= 100)
        return (double)0;
    if(dp[a][b][c]) {
        return mp[make_tuple(a, b, c)];
    }
    double x = a, y = b, z = c;
    mp[make_tuple(a, b, c)] = x * (f(x + 1, y, z) + 1) / (x + y + z) +
                              y * (f(x, y + 1, z) + 1) / (x + y + z) +
                              z * (f(x, y, z + 1) + 1) / (x + y + z);
    dp[a][b][c] = true;
    return mp[make_tuple(a, b, c)];
}
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if(A == 100 || B == 100 || C == 100) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, MAX_N) {
        REP(j, MAX_N) {
            REP(k, MAX_N) { dp[i][j][k] = false; }
        }
    }
    cout << fixed << setprecision(10) << f(A, B, C) << endl;
}