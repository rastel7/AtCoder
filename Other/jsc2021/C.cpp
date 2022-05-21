#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
map<ll, ll> prime_factorization(long long n)
{
    //map<ll,ll> first=素因数 second=first素因数の数
    map<ll, ll> res;
    for (int i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
        res[n]++;
    return res;
}
int main()
{
    ll A, B;
    cin >> A >> B;
    for (ll ans = B; ans >= 1; --ans)
    {
        ll cnt = 0;
        for (ll i = 1; i * ans <= B; ++i)
        {
            if (A <= i * ans)
                cnt++;
        }
        if (cnt > 1)
        {
            cout << ans << endl;
            return 0;
        }
    }
}