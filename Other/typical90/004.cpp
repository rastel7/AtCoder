#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    REP(i, H) REP(j, W) cin >> A[i][j];
    vector<int> Tate(H), Yoko(W);
    REP(i, H) REP(j, W) {
        Tate[i] += A[i][j];
        Yoko[j] += A[i][j];
    }
    REP(i, H) {
        REP(j, W) {
            cout << Tate[i] + Yoko[j] - A[i][j];
            if(j != W - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}