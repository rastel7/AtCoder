#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string Y = "YAKI";
    string S;
    cin >> S;
    if (S.size() < 4) {
        cout << "No" << endl;
        return 0;
    }
    REP(i, 4) {
        if (S[i] != Y[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}