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
    while(T--) {
        ll x;
        cin >> x;
        if(x % 2 != 0) {
            cout << "Odd" << endl;
        } else {
            if(x % 4 == 0) {
                cout << "Even" << endl;
            } else {
                cout << "Same" << endl;
            }
        }
    }
}