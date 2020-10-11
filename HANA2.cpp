#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;
const int MOD = 10000000;
int dp[201][201][3], a[201][201], n, m;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
    dp[1][1][1] = 1;
    for (int i = 2; i <= m; ++i) if (a[1][i] != -1)
    {
        if (a[1][i] == a[1][i - 1] || i - 1 == 1)
        {
            dp[1][i][1] = dp[1][i - 1][1];
            dp[1][i][2] = dp[1][i - 1][2];
        } else dp[1][i][2] = dp[1][i - 1][2] + dp[1][i - 1][1];
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= m; ++j) if (a[i][j] != -1)
        {
            if (a[i][j] == a[i - 1][j] || (i - 1 == 1 && j == 1) || (i == n && j == m))
            {
                dp[i][j][1] = dp[i - 1][j][1];
                dp[i][j][2] = dp[i - 1][j][2];
            }
            else dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];

            if (a[i][j] == a[i][j - 1] || (i == 1 && j - 1 == 1) || (i == n && j == m))
            {
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1])%MOD;
                dp[i][j][2] = (dp[i][j][2] + dp[i][j - 1][2])%MOD;
            }
            else dp[i][j][2] = (dp[i][j][2] + dp[i][j - 1][1] + dp[i][j - 1][2])%MOD;
        }
        printf("%d", dp[n][m][2]);
}
