#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll K;cin >> K;
    ll N = 50;
    vector<ll> A(N);
    ll add = (K) / 50;
    if(K <= 50) {
        REP(i, N) {
            if(i < K) {
                A[i] += 50;
            }

        }
    } else {
        REP(i, N) {
            if(i < (K % N)) {
                A[i] += 1 + K % 50;
            }
            A[i] += add + (49 - K % 50);
        }
        if(K % 50 == 0) {
            REP(i, N) {
                A[i] = 49 + K / 50;
            }
        }
    }
    cout << N << endl;
    for(auto a : A) {
        cout << a << " ";
    }
    cout << endl;
}