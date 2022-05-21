#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    vector<int> N(4);
    REP(i, 4)cin >> N[i];
    sort(N.begin(), N.end());
    if(N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}