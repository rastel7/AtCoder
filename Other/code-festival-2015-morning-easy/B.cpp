#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N;
    string S;
    cin >> N >> S;
    if(N % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    REP(i, N / 2) {
        if(S[i] != S[N / 2 + i])ans++;
    }
    cout << ans << endl;
}