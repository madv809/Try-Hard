#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const LL INF = 10000000009;
int u[101][101], path[101], n, m, cou;
LL dp[101][101], c[101][101];

LL go (int n, int m)
{
    if (n == 0) return 0;
    LL &ans = dp[n][m], k;
    if (ans != -1) return ans;
    ans = go(n - 1, m);
    for (int i = 1; i <= m; ++i)
    {
        k = c[n][i] + go(n - 1, m - i);
        if (ans < k)
        {
            ans = k;
            u[n][m] = i;
        }
    }
    return ans;
}

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) scanf("%lli", &c[i][j]);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= m; ++i) dp[0][i] = 0;
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    printf("%lli\n", go(n, m));
    while (n)
    {
        path[++cou] = u[n][m];
        m -= u[n][m]; --n;
    }
    for (cou; cou >= 1; --cou) printf("%d\n", path[cou]);
}
