#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int A, B;
    cin >> A >> B;
    if(A + B >= 15 && B >= 8) {
        cout << 1 << endl;
        return 0;
    }
    if(A + B >= 10 && B >= 3) {
        cout << 2 << endl;
        return 0;
    }
    if(A + B >= 3) {
        cout << 3 << endl;
        return 0;
    }
    cout << 4 << endl;
}