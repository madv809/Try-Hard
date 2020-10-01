#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const int INF = 1000000009;
int dp[101][52][50001], c[101], n;
bool vist[101][52][50001];

int go (int n, int k, int state)
{
    if (state < 0) return -INF;
    if (n == 0)
    {
        if (k == 0) return 0;
        else return -INF;
    }
    int ans = dp[n][k][state];
    if (vist[n][k][state]) return ans;
    vist[n][k][state] = 1;
    ans = -INF;
    ans = max(ans, max(go(n - 1, k, state), c[n] + go(n - 1, k - 1, state - c[n])));
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &c[i]);
        sum += c[i];
    }
    int best = go(n, n/2, sum/2);
    if (n&1) best = max(best, go(n, n/2 + 1, sum/2));
    int tmp = sum - best;
    if (best > tmp) swap(tmp, best);
    printf("%d %d", best, tmp);
}
