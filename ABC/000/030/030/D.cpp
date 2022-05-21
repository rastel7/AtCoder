#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n, a;
    cin >> n >> a, a--;
    string s;
    cin >> s;
    vector<int> B(n);
    REP(i, n)cin >> B[i], B[i]--;
    int ans;
    if(s.size() <= 7) {
        int k = stoi(s);
        REP(i, k) {
            a = B[a];
        }
        ans = a + 1;
    } else {
        vector<int> vi(n, -1);
        int cnt = 0;
        int u = a;
        while(vi[u] == -1) {
            vi[u] = cnt;
            ++cnt;
            u = B[u];
        }
        int ofs = vi[u],
            per = cnt - ofs,
            md = 0;
        for(char c : s) {
            md = (md * 10 + (c - '0')) % per;
        }

        int k = (md - ofs % per + per) % per;
        for(int i = 0; i < k; ++i) {
            u = B[u];
        }
        ans = u + 1;
    }
    cout << ans << endl;
}