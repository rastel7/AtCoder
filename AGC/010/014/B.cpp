#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> mp;
    while(M--) {
        int a, b;
        cin >> a >> b;
        mp[a]++, mp[b]++;
    }
    for(auto val : mp) {
        if(val.second % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
