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
    for(int i = 0;i < (1 << 4);++i) {
        string tmp = "";
        if(i & 1 << 0) {
            tmp += "AKIH";
        } else {
            tmp += "KIH";
        }
        if(i & 1 << 1) {
            tmp += "AB";
        } else {
            tmp += "B";
        }
        if(i & 1 << 2) {
            tmp += "AR";
        } else {
            tmp += "R";
        }
        if(i & 1 << 3) {
            tmp += "A";
        } else {
            tmp += "";
        }
        if(tmp == S) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}