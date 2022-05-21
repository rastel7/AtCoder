#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    if (A * A + B * B < C * C)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}