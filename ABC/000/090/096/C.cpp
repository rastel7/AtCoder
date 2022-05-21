#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];
    REP(i, H) REP(j, W) {
        if(S[i][j] == '.')
            continue;
        bool b = false;
        REP(k, 4) {
            int ny = i + dy[k], nx = j + dx[k];
            if(ny < 0 || nx < 0 || nx >= W || ny >= H)
                continue;
            if(S[ny][nx] == '#')
                b = true;
        }
        if(!b) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}