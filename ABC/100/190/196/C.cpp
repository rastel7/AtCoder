#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 1;i < 1e6 + 100;++i) {
        string tmp = to_string(i);
        tmp = tmp + tmp;
        if(stol(tmp) <= N)ans++;
    }
    cout << ans << endl;
}