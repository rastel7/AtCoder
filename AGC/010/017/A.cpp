#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
    if(a == 0) return 1;
    if(a == 1) return n ;
    if(a % 2 == 1) return (n * longpow(n, a - 1, mod)) ;
    ll t = longpow(n, a / 2, mod) ;
    return (t * t) ;
}
map<ll, ll> prime_factorization(long long n) {
    //map<ll,ll> first=素因数 second=first素因数の数
    map<ll, ll> res;
    for(int i = 2; i <= n / i; i++) {
        while(n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n]++;
    return res;
}
ll C(int n, int r) {
    map<ll, ll> bunbo, bunsi;
    for(int i = 0;i < r;++i) {
        for(auto val : prime_factorization(i + 1)) {
            bunbo[val.first] += val.second;
        }
        for(auto val : prime_factorization(n - i)) {
            bunsi[val.first] += val.second;
        }
    }
    for(auto a : bunbo) {
        int mn = min(a.second, bunsi[a.first]);
        bunbo[a.first] -= mn, bunsi[a.first] -= mn;
        if(bunsi[a.first] == 0) {
            bunsi.erase(a.first);
        }
        
    }
    ll ret = 1;
    for(auto val : bunsi) {
        while(val.second) {
            ret *= val.first;
            val.second--;
        }
    }
    return ret;
}
int main() {
    int N, P;
    cin >> N >> P;
    vector<ll> A(N);
    map<int, ll> mp;
    REP(i, N) {
        cin >> A[i];
        mp[A[i] % 2]++;
    }
    ll ans = 0;
    ans = longpow(2, mp[0], INF);
    ll tmp = 0;
    int i;
    if(P == 1) {
        i = 1;
    } else {
        i = 0;
    }
    for(;i <= mp[1];i += 2) {
        if(i == 0) {
            tmp++;
            continue;
        }
        tmp += C(mp[1], i);
    }
    cout << tmp * ans << endl;
}