#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int n, l;
    cin >> n >> l;
    vector<int> A(n);
    REP(i, n)cin >> A[i];
    int id = -1;
    REP(i, n - 1) {
        if(A[i] + A[i + 1] >= l) {
            id = i;
            break;
        }
    }
    if(id == -1) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    REP(i, n - 1) {
        if(i == id) {
            break;
        }
        cout << i + 1 << endl;
    }
    for(int i = n - 2;i >= 0;i--) {
        if(i == id)break;
        cout << i + 1 << endl;
    }
    cout << id + 1 << endl;
}
