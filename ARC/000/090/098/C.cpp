#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    vector<int> WaE(n + 1), WaW(n + 1);
    REP(i, n) {
        WaE[i + 1] += WaE[i];
        WaW[n - 1 - i] += WaW[n - i];
        if (S[i] == 'W')WaE[i+1]++;
        if (S[n - 1 - i] == 'E')WaW[n - 1 - i]++;
    }
    ll ans = 1e10;
    for (int i = 0;i < n;++i) {
        ans = min<ll>(ans, WaE[i] + WaW[i + 1]);
    }
    cout << ans << endl;
}