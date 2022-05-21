#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int md[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)md[2]++;
    while(y % (m * d)) {
        d++;
        if(d > md[m])d = 1, m++;
        if(m > 12) {
            y++, m = 1;
        }
    }
    printf("%d/%02d/%02d\n", y, m, d);
}