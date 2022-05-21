#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main() {
    string S;
    cin >> S;
    int a, b;
    cin >> a >> b;
    swap(S[a - 1], S[b - 1]);
    cout << S << endl;
}