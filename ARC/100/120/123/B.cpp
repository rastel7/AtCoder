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
    vector<ll> A(N), B(N), C(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    int ans = 0;
    int a = A.size() - 1, b = B.size() - 1;
    for(int c = C.size() - 1; c >= 0; c--) {
        ll c_num = C[c];
        bool brea = false;
        while(true) {
            if(b < 0) {
                brea = 1;
                break;
            }
            if(B[b] < c_num) {
                break;
            }
            b--;
        }
        if(brea)
            break;
        ll b_num = B[b];
        while(true) {
            if(a < 0) {
                brea = 1;
                break;
            }
            if(A[a] < b_num) {
                break;
            }
            a--;
        }
        if(brea)
            break;
        ans++;
        a--, b--;
    }
    cout << ans << endl;
}