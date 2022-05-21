#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int K;
    int N, L;
bool binary(int x, vector<int> const &A) {
    int cnt = 0;
    int l = 0;
    REP(i, A.size()) {
        if(A[i] - l >= x) {
            cnt++, l = A[i];
        }
        if(cnt >= K)
            break;
    }
    if(L - l < x)
        return false;
    return cnt >= K ? true : false;
}
int main() {

    cin >> N >> L;

    cin >> K;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    int l = 0, r = 1e9+100;
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(binary(mid, A)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}





