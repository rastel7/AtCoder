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
    ll ans = N;
    set<int> s;
    for(ll i = 2;i * i <= N;++i) {
        if(s.find(i) != s.end())continue;
        s.insert(i);
        ll tmp = i * i;
        ans--;
        while(tmp <= N / i) {
            s.insert(tmp);
            ans--;
            tmp *= i;

        }
    }
    cout << ans << endl;
}