#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;

int main() {
    string S;
    cin >> S;
    string L;
    //L作成
    int l = -1, r = -1;
    REP(i, S.size()) {
        if(S[i] == '_') {
            continue;
        } else {
            l = i;
            break;
        }
    }
    if(l == -1) {
        //_しかない
        cout << S << endl;
        return 0;
    }
    for(int i = S.size() - 1;i >= 0;i--) {
        if(S[i] == '_') {
            continue;
        } else {
            r = i;
            break;
        }
    }
    for(int i = l;i <= r;++i) {
        L.push_back(S[i]);
    }
    //camel判定
    bool camel = true;
    REP(i, L.size()) {
        if(isupper(L[i])) {
            camel = false;
        }
        if(i != 0) {
            if(L[i - 1] == '_' && !islower(L[i])) {
                camel = false;
            }
        }else{
            if(!islower(L[i])){
                camel=false;
            }
        }
    }

    //camelcaseだった
    if(camel) {
        REP(i, S.size()) {
            if(i < l || r < i) {
                cout << S[i];
                continue;
            }
            int t = i - l;
            if(L[t] == '_')continue;
            if(t != 0 && L[t - 1] == '_') {
                cout << (char)toupper(L[t]);
            } else {
                cout << L[t];
            }
        }
        cout << endl;
        return 0;
    }

    //upper判定
    bool upper = true;
    REP(i, L.size()) {
        if(i == 0) {
            if(!islower(L[i])) {
                upper = false;
            }
            continue;
        }
        if(L[i] == '_') {
            upper = false;
        }
    }

    //upperだった
    if(upper) {
        REP(i, S.size()) {
            if(i < l || r < i) {
                cout << S[i];
                continue;
            }
            int t = i - l;
            if(isupper(L[t])) {
                cout << "_" << (char)tolower(L[t]);
            } else {
                cout << L[t];
            }
        }
        cout << endl;
        return 0;
    }
    //どっちでもない
    cout<<S<<endl;
}