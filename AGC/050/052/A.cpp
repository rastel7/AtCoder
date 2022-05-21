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
        int N;
        string S1, S2, S3;
        cin >> N >> S1 >> S2 >> S3;
        REP(i, N)cout << "1";
        REP(i, N)cout << "0";
        cout << "1" << endl;
    }
}