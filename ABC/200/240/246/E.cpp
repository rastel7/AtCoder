#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
ll dy[4] = {1, -1, 1, -1};
ll dx[4] = {1, 1, -1, -1};
int main() {
    ll N, Ax, Ay, Bx, By;
    cin >> N >> Ay >> Ax >> By >> Bx, Ay--, Ax--, By--, Bx--;
    vector<string> S(N);
    REP(i, N) cin >> S[i];
    auto OoR = [&](ll y, ll x) { return y < 0 || x < 0 || y >= N || x >= N; };
    vector<vector<int>> reach(N, vector<int>(N, -1));
    reach[Ay][Ax] = 0;
    queue<pair<int, int>> que;
    que.push({Ay, Ax});
    while(!que.empty()) {
        auto [y, x] = que.front();
        que.pop();
        REP(i, 4) {
            for(ll l = 1;; l++) {
                ll ny = y + dy[i] * l, nx = x + dx[i] * l;
                if(OoR(ny, nx))
                    break;
                if(S[ny][nx] == '#')
                    break;
                if(reach[ny][nx] != -1 && reach[ny][nx] != reach[y][x] + 1)
                    break;
                if(reach[ny][nx] == -1) {
                    reach[ny][nx] = reach[y][x] + 1;
                    que.push({ny, nx});
                }
            }
        }
    }
    cout << reach[By][Bx] << endl;
}