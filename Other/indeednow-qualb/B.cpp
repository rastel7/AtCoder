#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string s, t;
    cin >> s >> t;
    if(s.size() != t.size()) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, t.size()) {
        if(t == s) {
            cout << i << endl;
            return 0;
        }
        s.insert(s.begin(), s.back());
        s.pop_back();
    }
    cout << -1 << endl;
}