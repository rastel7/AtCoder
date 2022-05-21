#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 1e18+1e17;
    chmin(ans, a * b * abs(c / 2 - (c - c / 2)));
    chmin(ans, a * c * abs(b / 2 - (b - b / 2)));
    chmin(ans, c * b * abs(a / 2 - (a - a / 2)));
    cout << ans << endl;
}