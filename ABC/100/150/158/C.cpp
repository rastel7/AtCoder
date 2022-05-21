#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int A, B;
    cin >> A >> B;
    for(int i = 1;i < 100000;++i) {
        int a = i * 8 / 100, b = i * 10 / 100;
        if(a == A && b == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}