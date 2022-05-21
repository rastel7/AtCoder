#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string X;
    cin >> X;
    string ans = "";
    bool age = 0;
    REP(i, X.size()) {
        if(X[i] != '.') {
            ans += X[i];
            continue;
        }
        break;
    }
    cout << ans << endl;
}