#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>
#include <ctime>

using namespace std;
const LL MOD = 1000000009;
LL dp[1001][1001];
int t, n;

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i <= 1000; ++i) dp[i][i] = 1;
    for (int i = 2; i <= 1000; ++i)
        for (int j = i - 1; j >= 1; --j) dp[i][j] = (dp[i][j + 1] + dp[i - j][j])%MOD;
    while (t--)
    {
        scanf("%d", &n);
        printf("%lli\n", dp[n][2]);
    }
 }
