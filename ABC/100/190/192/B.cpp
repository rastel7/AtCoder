#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string S;
    cin >> S;
    REP(i, S.size() - 1) {
        i += 1;
        if(!('A' <= S[i] && S[i] <= 'Z')) {
            cout << "No" << endl;
            return 0;
        }

    }
    REP(i, S.size()) {
        if(!('a' <= S[i] && S[i] <= 'z')) {
            cout << "No" << endl;
            return 0;
        }
        i += 1;
    }
    cout << "Yes" << endl;
}