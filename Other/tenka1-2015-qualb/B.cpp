#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string S;
    cin >> S;

    int depth = 0;
    bool b = false;
    if(S == "{}") {
        b = true;
    }
    REP(i, S.size()) {
        if(S[i] == '{')depth++;
        if(S[i] == '}')depth--;
        if(S[i] == ':' && depth == 1) {
            b = true;
        }
    }
    printf("%s\n", b ? "dict" : "set");
}