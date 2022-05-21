#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll B, C;
    cin >> B >> C;
    ll ans = 0;
    ll cnt = C / 2;
    if (C == 1) {
        if (B == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
        return 0;
    }
    if (B == 0) {
        ans += cnt * (ll)2 + (ll)1;
        if (C % 2 == 0)ans--;
        cout << ans << endl;
        return 0;
    }

    if (B < 0) {
        cnt = (C - 1) / 2;
        if (cnt >= abs(B)) {
            ans += max<ll>(0, (abs(B) * (ll)2) + (ll)1);
        }
        else {
            ans += 2 * cnt;
            if (C % 2 == 0)ans--;
            ans++;
            if (C != 1) {
                ans++;
            }
        }
        cnt = C / (ll)2;
        ans += cnt * (ll)2;
        if (C % (ll)2 == 0)ans--;
        cout << ans << endl;
        return 0;
    }
    if (cnt >= B) {
        ans += max<ll>(0, (B * (ll)2) + (ll)1);
    }
    else {
        ans += (ll)2 * cnt;
        if (C % (ll)2 == 0)ans--;
        ans++;
        if (C != (ll)1) {
            ans++;
        }
    }
    C--;
    cnt = C / (ll)2;
    ans += cnt * (ll)2;
    if (C % (ll)2 == 0)ans--;
    cout << ans << endl;
}