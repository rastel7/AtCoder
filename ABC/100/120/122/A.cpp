#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    char b;
    cin >> b;
    switch(b) {
    case 'A':
        cout << "T" << endl;
        break;
    case 'C':
        cout << "G" << endl;
        break;
    case 'G':
        cout << "C" << endl;
        break;
    case 'T':
        cout << "A" << endl;
        break;
    default:
        break;
    }
}