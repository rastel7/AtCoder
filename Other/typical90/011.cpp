  #include<bits/stdc++.h>
  using namespace std;
  #define REP(i, n) for (int i = 0; i < (int)(n); i++)
  #define OUT(V) for(int i=0;i<(int)V.size();++i){cout<<V[i]<<" ";}cout<<endl;
  typedef long long ll;
  typedef pair<int, int> P;
  const int INF = 1e9;
  const ll MOD = 1000000007;
  const int MAX_N = 10000;
  ll dp[MAX_N + 100][MAX_N + 100];
  template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
  int main() {
    int N;
    cin >> N;
    vector<ll> D(N), C(N), S(N);
    vector<tuple<ll, ll, ll>> A(N);
    REP(i, N) {
      ll a, b, c;
      cin >> a >> b >> c;
      A[i] = make_tuple(a, b, c);
    }
    sort(A.begin(), A.end());
    REP(i, N) {
      D[i] = get<0>(A[i]);
      C[i] = get<1>(A[i]);
      S[i] = get<2>(A[i]);
    }
    for(int i = 0;i < N;++i) {
      for(int j = 1;j <= MAX_N;++j) {
        if(C[i] <= j && j <= D[i]) {
          dp[i + 1][j] = max(dp[i][j], dp[i][j - C[i]] + S[i]);
        } else {
          dp[i + 1][j] = dp[i][j];
        }
      }
    }
    ll mx = 0;
    REP(i, 5010)chmax(mx, dp[N][i]);
    cout << mx << endl;
  }