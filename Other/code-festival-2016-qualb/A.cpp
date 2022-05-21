#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
const string fes = "CODEFESTIVAL2016";
int main() {
    string S;
    cin >> S;
    int ans = 0;
    REP(i, S.size()) {
        if(fes[i] != S[i])
            ans++;
    }
    cout << ans << endl;
}