#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const int INF = 100000000;
int dp[201][201][4], c[201][3], n, k;

int val (int n, int i)
{
    int res = 0;
    if (i&2) res += c[n][0];
    if (i&1) res += c[n][1];
    return res;
}

int go(int n, int k, int state)
{
    if (n == 0)
    {
        if (k == 0) return 0;
        return -INF;
    }
    int &ans = dp[n][k][state];
    if (ans != -1) return ans;
    ans = -INF;
    for (int i = 1; i < 4; ++i)
        if ((state&i) != 0) ans = max(ans, val(n, i) + go(n - 1, k - (i != 3), i));
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &c[i][0], &c[i][1]);
    memset(dp, -1, sizeof(dp));
    printf("%d", go(n, k, 3));
}
