#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int H, W, X, Y;
    cin >> H >> W >> Y >> X, X--, Y--;
    vector<string> S(H);
    REP(i, H)cin >> S[i];
    int ans = 0;
    int x, y;
    x = X, y = Y;
    while(x >= 0 && S[y][x] == '.') {
        x--, ans++;
        if(x < 0)break;
    }
    x = X, y = Y;
    while(x < W && S[y][x] == '.') {
        x++, ans++;
        if(x >= W)break;
    }
    x = X, y = Y;
    while(y >= 0 && S[y][x] == '.') {
        y--, ans++;
        if(y < 0)break;
    }
    x = X, y = Y;
    while(y < H && S[y][x] == '.') {
        y++, ans++;
        if(y >= H)break;
    }
    cout << ans - 3 << endl;
}