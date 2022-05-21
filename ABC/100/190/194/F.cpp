#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
using mint = modint1000000007;
mint dp[2][18][2 * 100000 + 1000];
int retnum(char c) {
    if('0' <= c && c <= '9') {
        return c - '0';
    }
    return 10 + (c - 'A');
}
int main() {
    string N;
    int K;
    cin >> N >> K;
    vector<int> checked(16);
    dp[1][0][0]=1;
    for(int i = 0;i < (int)N.size();++i) {
        //超える可能性あり
        int num = retnum(N[i]);
        if(i!=0)dp[0][i][0]=1;
        for(int j = 0;j < retnum(N[i]);++j) {//ここで下 jは採用する数字
            if(i==0&&j==0)continue;
            for(int k = 0;k < 17;k++) {
                /*if(j==0){
                    dp[0][i + 1][0] += dp[1][i][0];
                    continue;
                }*/
                if(checked[j] == 1) {
                    dp[0][i + 1][k] += dp[1][i][k];
                } else {
                    dp[0][i + 1][k + 1] += dp[1][i][k];
                }
            }
        }
        //継続
        REP(k, 17) {
            if(checked[num] == 1) {
                dp[1][i + 1][k] += dp[1][i][k];
            } else {
                dp[1][i + 1][k + 1] += dp[1][i][k];
            }
        }
        checked[num]=1;//確認

        //なし
      

        REP(j,17){
            
            dp[0][i+1][j+1]+=(16-j)*dp[0][i][j];
            
            dp[0][i+1][j]+=j*dp[0][i][j];
        }
        
        REP(k,17){
            cout<<dp[1][i+1][k].val()<<" ";
        }
        cout<<endl;
        REP(k,17){
            cout<<dp[0][i+1][k].val()<<" ";
        }
        cout<<endl;
    }
    int siz=N.size();
    dp[0][siz][1]-=1;
    cout<<(dp[1][siz][K]+dp[0][siz][K]).val()<<endl;
}