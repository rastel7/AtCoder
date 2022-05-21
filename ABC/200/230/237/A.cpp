#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    ll N;
    cin >> N;
    if((1ll << 31ll) > N && -1 * (1ll << 31ll) <= N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}