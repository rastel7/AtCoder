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
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i = 0;i < 1000;++i) {
        string tmp = to_string(i);
        while(tmp.size() < 3) {
            tmp.insert(tmp.begin(), '0');
        }
        int id = 0;
        for(auto& c : S) {
            if(c == tmp[id])id++;
            if(id >= 3)break;
        }
        if(id == 3)ans++;
    }
    cout << ans << endl;
}