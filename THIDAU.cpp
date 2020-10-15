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
int dp[101], k, n;
pair <int, int> a[101];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i].first);
    for (int i = 1; i <= n; ++i)
    {
         scanf("%d", &a[i].second);
         dp[i] = a[i].second;
    }
    sort(a + 1, a + n + 1); int best;
    best = a[1].second;
    for (int i = 2; i <= n; ++i)
        for (int j = i - 1; j >= 1; --j) if (a[i].first - a[j].first >= k)
        {
            dp[i] = max(dp[i], dp[j] + a[i].second);
            best = max(best, dp[i]);
        }
    printf("%d", best);
}
