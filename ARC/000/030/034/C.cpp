#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
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
int main() {
    ll A, B;
    //auto v=prime_factorization(2592);
    cin >> A >> B;
    map<ll,ll> mp;
    for(int i=B+1;i<=A;++i){
        auto tmp=prime_factorization(i);
        for(auto &t:tmp)mp[t.first]+=t.second;
    }
    ll ans=1;
    for(auto &t:mp){ans*=t.second+1;}
    cout<<ans<<endl;
}
