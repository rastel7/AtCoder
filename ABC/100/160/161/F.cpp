#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    set<ll> s;
    ll t = N - 1;
    for(ll i = 1;i <= t / i;++i) {
        if(t % i == 0) {
            s.insert(i);
            s.insert(t/i);
        }
    }
    s.insert(t);
    for(ll i = 1;i <= N / i;++i) {
        if(N % i == 0) {
            s.insert(i);
            s.insert(N/i);
        }
    }
    s.insert(N);
    ll ans = 0;
    s.erase(1);
    for(auto i : s) {
        
        ll n = N;
        while(n % i == 0) {
            n /= i;
        }
        if(n % i == 1)ans++;
    }
    cout << ans << endl;
}