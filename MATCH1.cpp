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
int vist[101], Assigned[101], m, n, t;
vector <int> a[101];

bool go (int u)
{
    if (vist[u] == t) return 0;
    vist[u] = t;
    for (int v : a[u])
    {
        if (!Assigned[v] || go(Assigned[v]))
        {
            Assigned[v] = u;
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
    int u, v, c = 0;
    while (scanf("%d%d", &u, &v) > 0) a[u].push_back(v);
    FOR(i, 1, m)
    {
        ++t;
        c += go(i);
    }
    printf("%d\n", c);
    FOR(i, 1, n) if (Assigned[i]) printf("%d %d\n", Assigned[i], i);
}
