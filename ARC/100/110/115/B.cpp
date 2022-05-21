#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    if(N == 1) {
        ll c;
        cin >> c;
        cout << "Yes" << endl;
        cout << c << endl << 0 << endl;
        return 0;
    }
    vector<vector<ll>> C(N, vector<ll>(N));
    REP(i, N)REP(j, N)cin >> C[i][j];
    ll sum = 0;
    REP(i, N)REP(j, N)sum += C[i][j];
    if(sum % N != 0) {
        //cout << "No" << endl;
    }

    /*vector<ll> A(N), B(N);
    ll mn = 1e9;
    REP(i, N)mn = min(mn, C[0][i]);
    mn++;
    while(true) {
        mn--;
        A[0] = mn;
        REP(i, N) {
            B[i] = C[0][i] - A[0];
        }
        REP(i, N) {
            A[i] = C[i][0] - B[0];
        }
        bool b = true;
        REP(i, N) {
            if(A[i] < 0 || B[i] < 0) {
                b = false;
                break;
            }
        }
        if(!b)continue;
        REP(i, N)REP(j, N) {
            if(C[i][j] != A[i] + B[j]) {
                b = false;
                break;
            }
        }
        if(!b)continue;
        break;
    }*/
    ll mn = 1e15, y = 0, x = 0;
    vector<ll> A(N), B(N);
    REP(i, N)REP(j, N) {
        if(mn > C[i][j]) {
            mn = C[i][j];
            y = i, x = j;
        }
    }
    REP(i, N) {
        A[i] = C[i][x] - C[y][x];
    }
    REP(i, N) {
        B[i] = C[0][i] - A[0];
    }
    REP(i, N)REP(j, N) {
        if(C[i][j] != A[i] + B[j]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    REP(i, N) {
        cout << A[i];
        if(i != N - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    REP(i, N) {
        cout << B[i];
        if(i != N - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}