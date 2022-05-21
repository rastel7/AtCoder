#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    string S;
    cin >> S;
    bool same = 1;
    REP(i, 3) if(S[i] != S[i + 1]) same = 0;
    if(same) {
        cout << "Weak" << endl;
        return 0;
    }
    same = 1;
    REP(i, 3) {
        if((S[i] - '0' + 11) % 10 !=( S[i + 1]-('0')))
            same = 0;
    }
    if(same) {
        cout << "Weak" << endl;
        return 0;
    }
    cout << "Strong" << endl;
}