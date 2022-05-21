#include<bits/stdc++.h>
#include<atcoder/all>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
using mint = atcoder::modint1000000007;
mint mem[110000];
int main() {
    ll N, K;
    cin >> N >> K;
    mint ans = 0;
    for(ll i = K;i >= 1;i--) {
        ll c = K / i;
        mint add = mint(c).pow(N);
        for(ll j = 2;j * i <= K;++j) {
            add -= mem[i * j];
        }
        mem[i] = add;
        ans += add * i;
    }
    cout << ans.val() << endl;
}