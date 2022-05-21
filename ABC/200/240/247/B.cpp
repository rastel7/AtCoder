#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    REP(i, N) cin >> S[i] >> T[i];
    REP(i, N) {
        string s = S[i];
        bool ok = true;
        REP(j, N) {
            if(j == i)
                continue;
            if(s == T[j] || s == S[j]) {
                ok = false;
            }
        }
        if(ok)
            continue;
        ok = true;
        s = T[i];
        REP(j, N) {
            if(j == i)
                continue;
            if(s == T[j] || s == S[j]) {
                ok = false;
            }
        }
        if(ok)
            continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}