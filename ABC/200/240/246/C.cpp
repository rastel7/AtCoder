#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N, K, X;
    cin >> N >> K >> X;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    REP(i, N) {
        ll cnt = A[i] / X;
        if(cnt > K) {
            cnt = K;
        }
        K -= cnt;
        A[i] -= cnt * X;
    }
    sort(A.begin(), A.end(), greater<>());
    ll ans = 0;
    REP(i, N) {
        if(K != 0) {
            K--;
            continue;
        }
        ans += A[i];
    }
    cout << ans << endl;
}