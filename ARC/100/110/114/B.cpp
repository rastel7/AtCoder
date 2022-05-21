#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
using mint = modint998244353;
int main() {
    int n;
    cin >> n;
    vector<int> F(n);
    REP(i, n)cin >> F[i], F[i]--;
    vector<bool> B(n);
    int cnt = 0;
    for(int i = 0;i < n;++i) {
        if(B[i] == 1)continue;
        int now = i;
        set<int> s;
        while(true) {
            if(B[now] == 1) {
                cnt--;
                break;
            }
            if(s.find(now) != s.end())break;
            s.insert(now);
            now = F[now];
        }
        for(auto& x : s)B[x] = 1;
        cnt++;
    }
    //cout << cnt << endl;
    cout << (mint(2).pow(cnt) - 1).val() << endl;
}