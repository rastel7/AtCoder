#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    REP(i, N) cin >> S[i];
    vector<ll> A(N);
    REP(i, N) {
        for(auto c : S[i]) {
            ll x = c - 'a';
            A[i] |= (1 << x);
        }
    }
    ll ans = 0;
    for(int i = 0; i < (1 << N); ++i) {
        vector<int> T(26);
        for(int j = 0; j < N; ++j) {
            if(((i >> j) & 1)) {
                REP(k, 26) {
                    if((A[j] >> k) & 1) {
                        T[k]++;
                    }
                }
            }
        }
        ll tmp = 0;
        REP(j, 26) {
            if(T[j] == K)
                tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}