#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
int M = 52 * 52 * 52;
int chartoint(char c) {
    if('A' <= c && c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}
int stringtoint(char a, char b, char c) {
    return chartoint(a) * 52 * 52 + chartoint(b) * 52 + chartoint(c);
}
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> edge(N);
    vector<vector<int>> revGraph(M);
    vector<int> cnt(M);
    REP(i, N) {
        string s;
        cin >> s;
        int siz = s.size();
        edge[i] = make_pair(stringtoint(s[0], s[1], s[2]),
                            stringtoint(s[siz - 3], s[siz - 2], s[siz - 1]));
        cnt[edge[i].first]++;
        revGraph[edge[i].second].emplace_back(edge[i].first);
    }
    vector<int> ans(M, -1);
    queue<int> que;
    REP(i, M) {
        if(cnt[i] == 0) {
            ans[i] = 0;
            que.push(i);
        }
    }
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        for(int x : revGraph[t]) {
            if(ans[x] == -1) {
                cnt[x]--;
                if(ans[t] == 0) {
                    ans[x] = 1;
                    que.push(x);
                } else if(cnt[x] == 0) {
                    ans[x] = 0;
                    que.push(x);
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(ans[edge[i].second] == -1)
            cout << "Draw" << endl;
        if(ans[edge[i].second] == 0)
            cout << "Takahashi" << endl;
        if(ans[edge[i].second] == 1)
            cout << "Aoki" << endl;
    }
}
