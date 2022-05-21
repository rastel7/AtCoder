#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int ans = 0;
int S[17][17];
void dfs(int y, int x, int const H, int const W, int A, int B) {

    if(y == H) {
        ans++;
        return;
    }
    if(x == W) {
        dfs(y + 1, 0, H, W, A, B);
        return;
    }
    if(S[y][x] == 1) {
        dfs(y, x + 1, H, W, A, B);
        return;
    }
    if(A != 0) {
        if(x != W - 1) {
            if(S[y][x + 1] == 0) {
                S[y][x + 1] = 1;
                dfs(y, x + 1, H, W, A - 1, B);
                S[y][x + 1] = 0;
            }
        }
        if(y != H - 1) {
            if(S[y + 1][x] == 0) {
                S[y + 1][x] = 1;
                dfs(y, x + 1, H, W, A - 1, B);
                S[y + 1][x] = 0;
            }
        }
    }
    if(B != 0) {
        dfs(y, x + 1, H, W, A, B - 1);
    }
}
int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    dfs(0, 0, H, W, A, B);
    cout << ans << endl;
}