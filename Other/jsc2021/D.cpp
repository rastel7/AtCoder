#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
using mint = modint1000000007;
int main()
{
    ll N, P;
    cin >> N >> P;
    if (P == 2)
    {
        //cout << 0 << endl;
    }
    mint ans = mint(P - 1) * mint(P - 2).pow(N-1);
    cout << ans.val() << endl;
}