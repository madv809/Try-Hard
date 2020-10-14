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
int n, t;
LL dp[100001], croot[100001], nchild[100001];
vector <int> c[100001], adj[100001];

void go (int par, int u)
{
    if (adj[u].size() == 0)
    {
        ++nchild[u];
        return;
    }
    ++nchild[u];
    for (int i = 0; i < adj[u].size(); ++i) if (adj[u][i] != par)
    {
        int v = adj[u][i];
        go(u, v);
        croot[u] += nchild[v]*c[u][i] + croot[v];
        nchild[u] += nchild[v];
    }
}

void Solve(int par, int u, int w)
{
    if (u != 1) dp[u] = (dp[par] - (nchild[u]*w + croot[u])) + (nchild[1] - nchild[u])*w + croot[u];
    for (int i = 0; i <  adj[u].size(); ++i) if (adj[u][i] != par) Solve(u, adj[u][i], c[u][i]);
}

void reset()
{
    for (int i = 1; i <= n; ++i)
    {
        adj[i].clear();
        c[i].clear();
    }
    memset(dp, 0, sizeof(dp));
    memset(croot, 0, sizeof(croot));
    memset(nchild, 0, sizeof(nchild));
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        reset();
        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            c[u].push_back(w);
            c[v].push_back(w);
        }
        go(0, 1);
        dp[1] = croot[1];
        Solve(0, 1, 0);
        for (int i = 1; i <= n; ++i) printf("%lli\n", dp[i]);
    }
}
