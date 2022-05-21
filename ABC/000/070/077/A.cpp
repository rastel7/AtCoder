#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    vector<string> S(2);
    cin >> S[0] >> S[1];
    REP(i, 2)REP(j, 3) {
        if(S[i][j] != S[1 - i][2 - j]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}