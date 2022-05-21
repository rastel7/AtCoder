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
    int i=1;
    while(T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        REP(i, n)cin >> A[i];
        int cost = 0;
        for(int i = 0;i < n - 1;++i) {
            int mn = A[i], id = i;
            for(int j = i + 1;j < n;++j) {
                if(mn > A[j]) {
                    id = j, mn = A[j];
                }
            }
            cost += id - i + 1;
            reverse(A.begin() + i, A.begin() + id+1);
            OUT(A);
        }
        printf("Case #%d: %d\n",i++,cost);
    }
}