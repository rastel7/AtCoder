#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
void f(int i) {
    if(i % 2 == 1) {
        cout << "WIN" << endl;
    } else {
        cout << "LOSE" << endl;
    }
}
int main() {
    int n;
    cin >> n;
    set<string> s;
    vector<string> S(n);
    REP(i, n)cin >> S[i];
    REP(i, n) {
        if(i != 0) {
            if(S[i][0] != S[i - 1][S[i - 1].size() - 1]) {
                f(i);
                return 0;
            }
        }
        if(s.find(S[i]) != s.end()) {
            f(i);
            return 0;
        }
        s.insert(S[i]);
    }
    cout << "DRAW" << endl;
}