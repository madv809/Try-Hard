#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>
#include <ctime>

using namespace std;
const LL INF = 100000000000009;
pair <int, int> a[10001];
int n;
LL dp[1001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].second, &a[i].first);
    sort(a + 1, a + n + 1);
    LL best = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = a[i].first; j >= 0; --j)
        {
            dp[j] = max(dp[j], a[i].second + dp[j - 1]);
            best = max(best, dp[j]);
        }
    printf("%lli\n", best);
    for (int i = 1; i <= n; ++i) cout << a[i].second << ' ';
}
