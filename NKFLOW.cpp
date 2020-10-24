#define LL long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
const int INF = 1000000009;
int f[1001][1001], c[1001][1001], d[1001], vist[1001], n, m, t, S, T;
vector <int> a[1001];

bool BFS (int S, int T)
{
    memset(d, 0, sizeof(d));
    d[S] = 1;
    queue <int> q;
    q.push(S);
    while (q.size())
    {
        int u = q.front();
        if (u == T) return 1;
        q.pop();
        for (int v : a[u]) if (!d[v] && f[u][v] < c[u][v])
        {
            q.push(v);
            d[v] = d[u] + 1;
        }
    }
    return 0;
}

int go (int u, int Min)
{
    if (u == T) return Min;
    vist[u] = t;

    for (int v : a[u]) if (vist[v] != t && d[v] == d[u] + 1 && f[u][v] < c[u][v])
    {
        if (int x = go(v, min(Min, c[u][v] - f[u][v])))
        {
            f[u][v] += x;
            f[v][u] -= x;
            return x;
        }
    }

    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &S, &T);
    int u, v, z, res = 0;
    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &z);
        a[u].push_back(v);
        a[v].push_back(u);
        c[u][v] = z;
    }

    while (BFS(S, T))
    {
        ++t;
        while (int x = go(S, INF)) res += x;
    }
    printf("%d", res);
}
