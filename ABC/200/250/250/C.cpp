#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    REP(i, N) { A[i] = i; }
    vector<ll> x(Q);
    REP(i, Q) {
        cin >> x[i];
        x[i]--;
    }
    vector<ll> pos(N);
    REP(i, N) { pos[i] = i; }
    REP(i, Q) {
        int val = pos[x[i]];
        if(val == N - 1) {
            int val2 = val-1;
            int num = A[val2];
            swap(A[val2], A[val]);
            swap(pos[num], pos[x[i]]);
            continue;
        }
        int num = A[pos[x[i]] + 1];
        swap(A[val], A[val + 1]);
        swap(pos[num], pos[x[i]]);
    }
    REP(l, N) {
        cout << A[l] + 1;
        if(l != N - 1) {
            cout << " ";
        }
    }
    cout << endl;
}