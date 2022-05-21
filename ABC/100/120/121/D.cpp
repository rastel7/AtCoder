#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll f(ll x) {
    if(x <= 0) {
        return 0;
    }
    int tmp = 1;
    if(x % 4 == 0 || x % 4 == 3) {
        tmp = 0;
    }
    if(x % 2 == 0) {
        return tmp ^ x;
    }
    return tmp;
}
int main() {
    ll A, B;
    cin >> A >> B;
    cout << (f(A - 1) ^ f(B)) << endl;
}