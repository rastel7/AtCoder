#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    long double sm = 0;
    for(auto& i : S) {
        if(i == 'F')continue;
        switch(i) {
        case 'A':
            sm += 4;
            break;
        case 'B':
            sm += 3;
            break;

        case 'C':
            sm += 2;
            break;

        case 'D':
            sm += 1;
            break;

        default:
            break;
        }
    }
    sm /= (double)(S.size());
    cout << fixed << setprecision(10) << sm << endl;
}