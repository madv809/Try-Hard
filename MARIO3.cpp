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
const LL MOD = 1000000000;
int n;
LL dp[1001], a[1001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lli", &a[i]);
    dp[0] = 1; dp[1] = (a[1] != 2); dp[2] = (a[2] != 2)*(dp[1] + dp[0]*(a[2] != 1));
    for (int i = 3; i <= n + 1; ++i) if (a[i] != 2) dp[i] = (dp[i - 3]*(a[i - 3] != 2)*(a[i - 3] != 1)*(a[i] != 1) + dp[i - 2]*(a[i - 2] != 2)*(a[i] != 1) + dp[i - 1]*(a[i - 1] != 2))%MOD;
    printf("%lli ", dp[n + 1]);
}
