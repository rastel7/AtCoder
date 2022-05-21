#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> K = {0};
    int now = 0;
    REP(i, N) {
        now += A[i];
        now %= 360;
        K.emplace_back(now);
    }
    ll ans = 0;
    sort(K.begin(), K.end());
    REP(i, N - 1) { ans = max(ans, K[i + 1] - K[i]); }
    ans = max(ans, K[0] + (360 - K.back()));
    cout << ans << endl;
}