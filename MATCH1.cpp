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

using namespace std;
int assigned[101], visited[101], t, m, n;
vector <int> adj[101];

bool vist (int u)
{
    if (visited[u] == t) return 0;
    visited[u] = t;

    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (!assigned[v] || vist(assigned[v]))
        {
            assigned[v] = u;
            return 1;
        }
    }

    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &m, &n);
    int u, v;
    while (scanf("%d%d", &u, &v) > 0) adj[u].push_back(v);
    int c = 0;
    FOR(i, 1, m)
    {
        ++t;
        c += vist(i);
    }
    printf("%d\n", c);
    FOR (i, 1, n) if (assigned[i]) printf("%d %d\n", assigned[i], i);
}
