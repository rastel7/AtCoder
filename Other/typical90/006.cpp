#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int N, K;
int main() {
    cin >> N >> K;
    string S;
    cin >> S;
    vector<vector<int>> memo(27, vector<int>(N + 1, 1e9));
    for(int i = N - 1; i >= 0; i--) {
        REP(j, 27) { memo[j][i] = memo[j][i + 1]; }
        memo[S[i] - 'a'][i] = i;
    }
    string ans = "";
    int id = 0;
    for(int i = 0; i < K; i++) {
        for(int j = 0; j <= (int)('z' - 'a'); ++j) {
            int nex = ans.size() + (N - memo[j][id] + 1);
            if(ans.size() + (N - memo[j][id]) >= K && memo[j][id] <= N) {
                ans += (char)(j + 'a');
                id = memo[j][id] + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}