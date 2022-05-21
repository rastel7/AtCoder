#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e18;
const ll MOD = 1000000007;
struct A {
    int hoge;
    string str1, str2;
    char c[50] = "123465";
};
void save() {
    A a;
    a.hoge = 12;
    a.str1 = "hoge2";
    a.str2 = "hogehoge";
    a.c[0] = 'c';
    a.c[1] = '\0';
    FILE *fp = NULL;

    if((fp = fopen("doo.dat", "wb")) == NULL) {
        return;
    }
    fwrite(&a, sizeof(A), 1, fp);
    fclose(fp);
    return;
}
void load() {
    A a;
    FILE *fp = NULL;
    if((fp = fopen("doo.dat", "rb")) == NULL) {
        return;
    }
    fread(&a, sizeof(A), 1, fp);
    fclose(fp);
    cout << a.hoge << endl;
    cout << a.str1 << endl;
    cout << a.str2 << endl;
    cout<<a.c<<endl;
    return;
}
int main() {
    time_t timer; /* 時刻を取り出すための型（実際はunsigned long型） */
    struct tm *local; /* tm構造体（時刻を扱う */

    /* 年月日と時分秒保存用 */
    int year, month, day, hour, minute, second;

    timer = time(NULL);        /* 現在時刻を取得 */
    local = localtime(&timer); /* 地方時に変換 */

    /* 年月日と時分秒をtm構造体の各パラメタから変数に代入 */
    year = local->tm_year + 1900; /* 1900年からの年数が取得されるため */
    month = local->tm_mon + 1; /* 0を1月としているため */
    day = local->tm_mday;
    hour = local->tm_hour;
    minute = local->tm_min;
    second = local->tm_sec;

    /* 現在の日時を表示 */
    printf("%d年%d月%d日 %d時%d分%d秒です\n", year, month, day, hour, minute,
           second);
    save();

    load();
}