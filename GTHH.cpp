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
int n;
LL dp[100001][2], a[100001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lli", &a[i]);
    for (int i = 2; i <= n; ++i)
    {
        dp[i][1] = dp[i - 1][0] + abs(a[i] - 1);
        dp[i][0] = dp[i - 1][1] + abs(1 - a[i - 1]);
    }
    printf("%lli", max(dp[n][0], dp[n][1]));
}
