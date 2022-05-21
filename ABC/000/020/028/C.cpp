#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int A[5];
    REP(i, 5)cin >> A[i];
    vector<int> V(0);
    for(int i = 0;i < 5;++i) {
        for(int j = i + 1;j < 5;++j) {
            for(int k = j + 1;k < 5;++k) {
                V.push_back(A[i] + A[j] + A[k]);
            }
        }
    }
    std::sort(V.begin(), V.end());
    V.erase(std::unique(V.begin(), V.end()), V.end());
    sort(V.begin(), V.end(), greater<>());
    cout << V[2] << endl;
}