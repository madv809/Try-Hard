#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const LL MOD = 1000000007;
LL dp[5][1000001], c[5];
int m, n, k;

LL powMod(LL a, int p)
{
    LL res = 1;
    while (p)
    {
        if (p&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        p >>= 1;
    }
    return res;
}

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= n; ++i) dp[1][i] = 1;
    for (int i = 2; i <= 4; ++i)
        for (int j = i; j <= n; ++j) dp[i][j] = (dp[i][j - 1]*i + dp[i - 1][j - 1]*i)%MOD;
    c[1] = 4; c[2] = 6; c[3] = 4; c[4] = 1;
    LL ans = 0;
    for (int i = k; i <= 4; ++i) ans = (ans + dp[i][n]*c[i])%MOD;
    ans = powMod(ans, m);
    printf("%lli", ans);
}
