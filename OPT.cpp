#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;
const LL INF = 1000000000009;
int dp[101][101], c[101], n, k;
vector <int> adj[101];
bool vist[101];

void go (int v)
{
    vist[v] = 1;
    for (int i : adj[v]) if (!vist[i])
    {
        go(i);
        for (int j = k; j >= 1; --j)
            for (int m = 1; m <= j; ++m) dp[v][j] = max(dp[v][j], dp[v][m] + dp[i][j - m]);
    }
}

void reset()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= k; ++j) dp[i][j] = 0;
    memset(vist, 0, sizeof(vist));
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    int m, v, best = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &c[i], &m);
        while (m--)
        {
            scanf("%d", &v);
            adj[i].push_back(v);
        }
        dp[i][1] = c[i];
    }
    for (int i = 1; i<= n; ++i)
    {
        reset();
        go(i);
        for (int j = 1; j <= k; ++j) best = max(best, dp[i][j]);
    }
    printf("%d", best);
 }
