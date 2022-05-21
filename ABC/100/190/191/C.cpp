#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    REP(i, h)cin >> S[i];
    int ans = 0;
    for (int x = 1;x < w;++x) {
        for (int y = h - 1;y > 0;--y) {
            int cnt = 0;
            if (S[y][x] == '#')cnt++;
            if (S[y - 1][x] == '#')cnt++;
            if (S[y][x - 1] == '#')cnt++;
            if (S[y - 1][x - 1] == '#')cnt++;
            if (cnt % 2 == 1)ans++;
        }
    }
    cout << ans << endl;
}