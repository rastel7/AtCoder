#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    vector<int> A, B;
    REP(i, S.size()) {
        if(S[i] == '0')
            A.push_back(i + 1);
        if(T[i] == '0')
            B.push_back(i + 1);
    }
    if(A.size() != B.size()) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    REP(i, A.size()) {
        if(A[i] != B[i])
            ans++;
    }
    cout << ans << endl;
}