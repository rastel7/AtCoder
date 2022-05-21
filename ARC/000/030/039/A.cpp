#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
int main() {
    string A, B;
    cin >> A >> B;
    int ans = -INF;
    REP(i, 3) {
        string a = A, b = B;
        a[i] = '9';
        chmax(ans, stoi(a) - stoi(b));
    }
    REP(i, 3) {

        string a = A, b = B;
        if(i == 0) { b[i] = '1'; } else {
            b[i] = '0';
        }

        chmax(ans, stoi(a) - stoi(b));
    }
    cout << ans << endl;
}