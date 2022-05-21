#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "Won" << endl;
    }
    else {
        cout << "Lost" << endl;
    }
}