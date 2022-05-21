#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c) {
        cout << a << endl;
    } else if(a == b || b == c || a == c) {
        if(a == b) {
            cout << c << endl;
        } else if(b == c) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    } else {
        cout << 6 - a - b - c << endl;
    }
}