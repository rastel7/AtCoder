#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll h, w;
    cin >> h >> w;
    if(h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll ans = h * w / 2;
    if(h % 2 == 1 && w % 2 == 1) {
        ans++;
    }
    cout << ans << endl;
}