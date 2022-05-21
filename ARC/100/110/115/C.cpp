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
    vector<set<int>> s(N + 10);
    vector<int> Ans(N + 10);
    Ans[1] = 1;
    for(ll i = 1;i <= N;++i) {
        if(i != 1) {
            for(int j = 2;;j++) {
                if(!s[i].count(j)) {
                    Ans[i] = j;
                    break;
                }

            }
        }
        for(ll j = 1;j * i <= N;++j) {
            s[i * j].insert(Ans[i]);
        }

    }
    for(int i = 1;i <= N;++i) {
        cout << Ans[i];
        if(i != N) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}