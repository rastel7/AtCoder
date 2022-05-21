#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    REP(i, n)cin >> S[i];
    int ans = 0;
    REP(i, n) {
        REP(j, S[i].size())if(S[i][j] == 'x')ans++;
    }
    REP(i, S[0].size())if(S[0][i] == 'o')ans++;
    for(int i = 1;i < n;++i) {
        REP(j, S[i].size()) {
            if(S[i][j] == 'o' && S[i - 1][j] != 'o')ans++;
        }
    }
    cout << ans << endl;
}