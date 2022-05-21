#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
bool f(vector<int>& l, vector<int>& r) {
    //rのほうが小さかったらtrue
    REP(i, l.size()) {
        if(l[i] == r[i])continue;
        if(l[i] > r[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n;
    vector<int> S(n);
    REP(i, n) {
        cin >> S[i], S[i]--;
    }
    cin >> m;
    vector<vector<int>> P(m, vector<int>(n));
    REP(i, m) {
        REP(j, n) {
            cin >> P[i][j], P[i][j]--;
        }
    }
    vector<int> Ans = S;
    vector<int> Perm(m);
    REP(i, m) { Perm[i] = i; }
    do {
        vector<int>  tmp = S;
        REP(i, Perm.size()) {
            int id = Perm[i];
            vector<int> nex = tmp;
            REP(j, P[i].size()) {
                nex[P[id][j]] = tmp[j];
            }
            if(f(Ans, nex)) {
                Ans = nex;
            }
            tmp = nex;
        }
    } while(next_permutation(Perm.begin(), Perm.end()));
    REP(i, Ans.size()) {
        cout << Ans[i] + 1;
        if(i != Ans.size() - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}