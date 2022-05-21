#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    vector<ll> T(N);
    REP(i, N) cin >> S[i] >> T[i];
    ll ans = 0, ansscore = -1e16;
    set<string> ed;
    REP(i, N) {
        if(ed.count(S[i]))
            continue;
        ed.insert(S[i]);
        if(T[i] > ansscore) {
            ans = i + 1;
            ansscore = T[i];
        }
    }
    cout << ans << endl;
}