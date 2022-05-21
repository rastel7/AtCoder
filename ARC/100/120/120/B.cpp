#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];
    vector<vector<char>> C(H + W);
    mint ans = 1;
    REP(i, H) REP(j, W) C[i + j].push_back(S[i][j]);
    REP(i, H + W) {
        int r = 0, b = 0;
        if(C[i].size() == 0)
            continue;
        for(auto &a : C[i]) {
            if(a == 'R')
                r++;
            if(a == 'B')
                b++;
        }
        if(r && b) {
            ans = 0;
        }
        if(r == 0 && b == 0) {
            ans *= 2;
        }
    }
    cout << ans.val() << endl;
}