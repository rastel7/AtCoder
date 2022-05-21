#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    REP(i, N)cin >> S[i];
    sort(S.begin(), S.end());
    REP(i, N) {
        cout << S[i];
    }
    cout << endl;
}