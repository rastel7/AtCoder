#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> odd, even;
    REP(i, N) {
        if(A[i] % 2 == 0)
            even.emplace_back(A[i]);
        else
            odd.emplace_back(A[i]);
    }
  
}
int main() {
    ll T;
    cin >> T;
    while(T--)
        solve();
}