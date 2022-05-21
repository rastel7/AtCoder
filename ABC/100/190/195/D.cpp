#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<P> A(n);
    REP(i, n)cin >> A[i].second >> A[i].first;
    sort(A.begin(), A.end(), greater<>());
    vector<P> B(m);
    REP(i, m) {
        cin >> B[i].first;
        B[i].second = i;
    }
    sort(B.begin(), B.end());
    while(q--) {
        int l, r;
        cin >> l >> r, l--, r--;
        ll ans = 0;
        vector<int> dp(m);
        REP(i, n)REP(j, m) {
            if(l <= B[j].second && B[j].second <= r)continue;
            if(dp[j] == 1)continue;
            if(A[i].second <= B[j].first) {
                dp[j] = 1;
                //cout << B[j].second << endl;
                ans += A[i].first;
                break;
            }
        }
        cout << ans << endl;
    }
}