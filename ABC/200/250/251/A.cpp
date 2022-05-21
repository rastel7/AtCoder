#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {

    string S;
    cin >> S;
    auto c = S;
    while(S.size() < 6) {
        S += c;
    }
    cout << S << endl;
}