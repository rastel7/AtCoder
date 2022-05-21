#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int a;
    cin >> a;
    int x = a / 100, y = (a / 10) % 10, z = a % 10;
    cout << a + y * 100 + z * 10 + x + z * 100 + x * 10 + y << endl;
}