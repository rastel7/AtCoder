#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    while(N--) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int mx = 0, ans = -1;
    REP(i, 1e5 + 3) {
        int tmp = mp[i - 1] + mp[i] + mp[i + 1];
        if(tmp > mx) {
            mx = tmp;
            ans = i;
        }
    }
    cout << mx << endl;
}