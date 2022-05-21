#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int T;
    cin >> T;
    for(int i = 1;i <= T;++i) {
        int N, C;
        cin >> N >> C;
        if(N - 1 > C || N * (N + 1) / 2 - 1 < C) {
            printf("Case #%d: IMPOSSIBLE\n", i);
            continue;
        }
        vector<int> ans(N);
        for(int j = 0;j < N;++j) {
            if(j % 2 == 0) {
                ans[N - 1 - j / 2] = j + 1;
            } else {
                ans[j / 2] = j + 1;
            }
        }
        int now = N - 1, l = N - 1, id = 0;
        for(int j = N * (N + 1) / 2 - 1;j > C;--j) {
            reverse(ans.begin()+id, ans.begin() + now + 1);
            now--;
            reverse(ans.begin()+id, ans.begin() + now + 1);
            if(now == id) {
                id++;
                now = l;
            }
        }
        printf("Case #%d: ", i);
        for(int j = 0;j < N;++j) {
            cout << ans[j];
            if(j != N - 1)cout << " ";
        }
        cout << endl;
    }
}