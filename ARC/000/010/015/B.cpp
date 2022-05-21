#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int ans[6];
int main() {
    int n;
    cin >> n;
    REP(i, 6)ans[i] = 0;
    while(n--) {
        double l, r;
        cin >> r >> l;
        if(r >= 35)ans[0]++;
        if(30 <= r && r < 35)ans[1]++;
        if(25 <= r && r < 30)ans[2]++;
        if(25 <= l)ans[3]++;
        if(l < 0 && 0 <= r)ans[4]++;
        if(r < 0)ans[5]++;
    }
    REP(i, 6) {
        cout << ans[i];
        if(i != 5)cout << " ";
    }
    cout << endl;
}