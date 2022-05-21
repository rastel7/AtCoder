#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    ans += max(0, (4 - x) * 100000) + max(0, (4 - y) * 100000);
    if (x == 1 && y == 1) {
        ans += 400000;
    }
    cout << ans << endl;
}