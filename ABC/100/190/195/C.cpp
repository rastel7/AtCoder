#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
    if(a == 0) return 1;
    if(a == 1) return n % mod;
    if(a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
    ll t = longpow(n, a / 2, mod) % mod;
    return (t * t) % mod;
}
int main() {
    string N;
    cin >> N;
    ll cnt = 0;
    ll ckdc = stol(N);
    /*for(int i = 0;i <= ckdc;++i) {
        if(i / 1000 != 0)cnt += (to_string(i).size() - 1) / 3;
    }*/
    //cout << cnt << endl;
    //return 0;
    N[0]--;
    ll ans = 0;
    ll tmp = (N.size() - 1) / 3;
    ans += stol(N) * tmp;
    //cout << ans << endl;
    /*for(int i = 0;i < N.size();++i) {
        int c = N[i] - '0';
        ll t = longpow(10, (N.size() - 1) - i, 1e18);
        cout << t << endl;

        ans += c * tmp * longpow(10, (N.size() - 1) - i, 1e18);
    }*/
    vector<ll> dp(100, 0);
    dp[4] = 1;
    for(int i = 5;i <= N.size();++i) {
        ll tmp = (i - 2) / 3;
        ll sm = dp[i - 1] + tmp * 9 * longpow(10, (i - 2), 1e18);
        if(i % 3 == 1)sm++;
        dp[i] = sm;
        //cout << sm << endl;
    }

    cout << ans + dp[N.size()] << endl;
}