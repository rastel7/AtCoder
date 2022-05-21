#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 2e18;
const ll MOD = 1000000007;
int main() {
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    if(K % 2 == 0) {
        cout << A - B << endl;
    } else {
        cout << B - A << endl;
    }
}