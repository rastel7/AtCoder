#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> H(n);
    REP(i, n)cin >> H[i];
    vector<int> A(m), B(m);
    vector<vector<int>> G(n, vector<int>(0));
    REP(i, m) {
        cin >> A[i] >> B[i], A[i]--, B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    int ans = 0;
    REP(i, n) {
        bool b = true;
        REP(j, G[i].size()) {
            if(H[i] <= H[G[i][j]]) {
                b = false;
            }
        }
        if(b)ans++;
    }
    cout << ans << endl;
}