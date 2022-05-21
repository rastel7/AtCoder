#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
    double n, m, d;
    cin >> n >> m >> d;
    double ans = 0;
    if(d == 0) {
        ans = (m-1) / n;
    }else{
        ans=((m-1)*(n-d)*2)/pow(n,2);
    }
    cout <<fixed<<setprecision(10)<< ans << endl;
}