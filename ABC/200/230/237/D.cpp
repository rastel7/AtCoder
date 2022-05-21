#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    REP(i, H) REP(j, W) cin >> A[i][j];
    REP(i, W) {
        REP(j, H) {
            cout << A[j][i];
            if(j != H - 1)
                cout << " ";
        }
        cout << "\n";
    }
}