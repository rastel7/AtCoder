#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll cnt[210101];
const ll MAX_A = 210101;
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cnt[A[i]]++;
    ll ans = 0;
    for(ll j = 1; j < MAX_A; ++j) {
        for(ll k = 1; k * j < MAX_A; ++k) {
            ll i = j * k;
            ll tmp = 0;
            /*if(j == k && k == i && i == j) {
                // 1
                tmp = cnt[j] * (cnt[j] - 1) * (cnt[j] - 2);
            }else if(){

            }
            */
            tmp = cnt[i] * cnt[j] * cnt[k];
            ans += tmp;
        }
    }
    /*
    for(ll i = 2; i < MAX_A; ++i) {
        for(ll j = i+1; j * i < MAX_A - 10; ++j) {
            ans += cnt[j * i] * cnt[j] * cnt[i]*2;
        }
    }
    cerr << ans << endl;
    for(ll i = 2; i < MAX_A; ++i) {
        ans += cnt[1] * (cnt[i] * (cnt[i] - 1));
    }
    for(ll i = 1; i * i < MAX_A; ++i) {
        ans += cnt[i * i] * (cnt[i] * (cnt[i] - 1));
    }
    ans += cnt[1] * (cnt[1] - 1) * (cnt[1] - 2);
    */
    cout << ans << endl;
}