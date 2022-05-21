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
    cin >> N;
    vector<int> S(N);
    int zero = 0;
    REP(i, N) {
        cin >> S[i];
        if(S[i] == 0)zero++;
    }
    sort(S.begin(), S.end());
    int Q;
    cin >> Q;
    while(Q--) {
        int x;
        cin >> x;
        if(N - zero <= x) {
            cout << 0 << endl;
            continue;
        }
        cout << S[N - 1 - x] + 1 << endl;
    }
}