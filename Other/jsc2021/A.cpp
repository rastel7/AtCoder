#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
using mint = modint1000000007;
int main()
{
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    for (ll a = 1e8; a >= 0; a--)
    {
        if (X * a < Z * Y)
        {
            cout << a << endl;
            return 0;
        }
    }
}