#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    REP(i, N) {
        if(S[i] == '1') {
            if(i % 2 == 0) {
                cout << "Takahashi" << endl;
            } else {
                cout << "Aoki" << endl;
            }

            return 0;
        }
    }
}