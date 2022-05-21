#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int ok[(int)1e6 + 100];
int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    A.emplace_back(0);
    A.emplace_back(0);
    REP(i, N) for(int j = i + 1; j < N + 2; ++j) {
        for(int k = j + 1; k < N + 2; ++k) {
            if(i == j || j == k || i == k)
                continue;
            ll sum = A[i] + A[j] + A[k];
            if(sum <= W)
                ok[sum] = 1;
        }
    }
    ll sum = 0;
    REP(i, W) {
        // cerr << i << " " << ok[i + 1] << endl;
        sum += ok[i + 1];
    }
    cout << sum << endl;
}