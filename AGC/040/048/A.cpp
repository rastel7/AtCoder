#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
const string atc = "atcoder";
int main() {
    int T;
    cin >> T;
    while(T--) {
        string S;
        cin >> S;
        if(S > atc) {
            cout << 0 << endl;
            continue;
        }
        int id = 0;
        for(; id < S.size(); ++id) {
            if(S[id] != 'a')
                break;
        }
        if(id == S.size()) {
            cout << -1 << endl;
            continue;
        }
        if(S[id] <= 't') {
            cout << id  << endl;
        } else {
            cout << id-1  << endl;
        }
    }
}