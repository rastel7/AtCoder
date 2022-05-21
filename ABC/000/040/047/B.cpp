#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int W, H, N;
    cin >> W >> H >> N;
    vector<vector<int>> G(H, vector<int>(W, 0));
    while(N--) {
        int x, y, a;
        cin >> x >> y >> a;
        switch(a) {
        case 1:
            REP(i, H)REP(j, x) {
                G[i][j] = 1;
            }
            break;
        case 2:
            REP(i, H)for(int j = x;j < W;++j) {
                G[i][j] = 1;
            }
            break;
        case 3:
            REP(i, y)REP(j, W) {
                G[i][j] = 1;
            }
            break;
        case 4:
            for(int i = y;i < H;++i) {
                REP(j, W) {
                    G[i][j] = 1;
                }
            }
            break;
        default:
            break;
        }
    }
    int ans = 0;
    REP(i, H)REP(j, W) {
        if(G[i][j] == 0)ans++;
    }
    cout << ans << endl;
}