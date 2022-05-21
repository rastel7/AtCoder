#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    REP(i, N) cin >> S[i];
    REP(i, M) cin >> T[i];
    T.emplace_back("0000A00");
    int id = 0;
    REP(i, N) {
        if(S[i] == T[id]) {
            cout << "Yes\n";
            id++;
        } else {
            cout << "No\n";
        }
    }
}