#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const int INF = 32000, d = 1<<9;
int dp[2001][1<<10], a[2001], b[2001], D[2001], n, c;

bool check (int i, int j)
{
    for (int k = 1; k <= 9; ++k)
    {
        if (i - k <= 0) return 1;
        if ((j&(1 << k))&&(a[i] - a[i - k] == 1 || a[i] - a[i - k] == 8 || a[i] - a[i - k] == 9)) return 0;
    }
    return 1;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a, a + n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; ++i)
        if (a[i] != a[i - 1])
        {
            b[++c] = a[i];
            D[c] = 1;
        }
        else ++D[c];
    swap(n, c);
    for (int i = 1; i <= n; ++i) a[i] = b[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < (1<<10); ++j) if (!(j&1)) dp[i][j] = max(dp[i - 1][j >> 1], dp[i - 1][(j >> 1) + d]);
        else if (check(i, j)) dp[i][j] = max(dp[i - 1][j >> 1], dp[i - 1][(j >> 1) + d]) + D[i];
        else dp[i][j] = -INF;
    }
    int imax = 0;
    for (int i = 0; i < (1 << 10); ++i) if (imax < dp[n][i]) imax = dp[n][i];
    printf("%d", c - imax);
}
