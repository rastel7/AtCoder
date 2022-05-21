#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 1000;
    for(int i = 0;i < N;++i) {
        string l = S.substr(0, i), r = S.substr(i, N - i);
        vector<vector<int>> dp(l.size() + 1, vector<int>(r.size() + 1));
        REP(j, l.size() + 1)REP(k, r.size() + 1) {
            if(j != l.size())
                chmax(dp[j + 1][k], dp[j][k]);
            if(k != r.size())
                chmax(dp[j][k + 1], dp[j][k]);
            if(j != l.size() && k != r.size()) {
                if(l[j] == r[k]) {
                    chmax(dp[j + 1][k + 1], dp[j][k] + 1);
                }
            }
        }
        int mx = dp[l.size()][r.size()];
        //cout << l << " " << r << " " << mx << endl;
        ans = min(ans, N - dp[l.size()][r.size()] * 2);
    }
    cout << ans << endl;
}