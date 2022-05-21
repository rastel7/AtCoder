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
    map<int, ll> mp;
    REP(i, N) {
        string S;
        cin >> S;
        int cnt = 0;
        REP(j, S.size()) {
            if(S[j] == '1')cnt++;
        }
        mp[cnt % 2]++;
    }
    cout << mp[0] * mp[1] << endl;
}