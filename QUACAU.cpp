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
int dp[201], a[201], n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    dp[1] = a[1]; dp[2] = a[2];
    for (int i = 3; i <= n; ++i) dp[i] = min(dp[i - 1] + a[1] + a[i], dp[i - 2] + a[1] + a[i] + 2*a[2]);
    printf("%d", dp[n]);
}
