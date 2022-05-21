#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N;
    string S, X;
    cin >> N >> S >> X;
    set<int> dp = { 0 };
    reverse(S.begin(), S.end());
    reverse(X.begin(), X.end());
    REP(i, N) {
        int x = S[i] - '0';
        char c = X[i];
        set<int> next;
        if(c == 'T') {
            REP(j, 7) {
                if(dp.count((j * 10 + x) % 7) || dp.count((j * 10) % 7)) {
                    next.insert(j);
                }
            }
        } else {
            REP(j, 7) {
                if(dp.count((j * 10 + x) % 7) && dp.count((j * 10) % 7)) {
                    next.insert(j);
                }
            }
        }
        dp = next;
    }
    if(dp.count(0)) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}