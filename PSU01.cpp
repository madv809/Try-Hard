#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const LL MOD = 1000000007;
int m, n;
LL dp[2001][2001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) dp[i][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int k = 2; k <= m; ++k)
            for (int j = i; j <= n; j += i) dp[j][k] = (dp[j][k] + dp[i][k - 1])%MOD;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + dp[i][m])%MOD;
    printf("%lli", ans);
}
