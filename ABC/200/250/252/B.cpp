#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i];
    set<int> s;
    REP(i, K) {
        int a;
        cin >> a;
        s.insert(a - 1);
    }
    ll mx = 0;
    REP(i, N) {
        if(mx < A[i])
            mx = A[i];
    }
    bool ok = false;
    REP(i, N) {
        if(A[i] == mx) {
            if(s.count(i)) {
                ok = 1;
            }
        }
    }
    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}