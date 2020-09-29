#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const LL INF = 1000000000001;
LL dp[100005], a[100005];
int heap[100005], pos[100005], trace[100005], path[100005], h;
int n, k;

void add (int i)
{
    heap[++h] = i;
    pos[i] = h;
    int child = h, par = child/2;
    while (par)
    {
        if (dp[heap[par]] >= dp[i]) break;
        heap[child] = heap[par];
        pos[heap[child]] = child;
        child = par;
        par /= 2;
    }
    heap[child] = i; pos[i] = child;
}

void update (int v)
{
    dp[v] = -INF;
    int par = pos[v], child = par*2, p;
    while (child <= h)
    {
        if ((child + 1 <= h) && (dp[heap[child + 1]] >= dp[heap[child]])) p = child + 1;
        else p = child;
        if (dp[v] >= dp[heap[p]]) break;
        heap[par] = heap[p];
        pos[heap[par]] = par;
        par = p; child = par*2;
    }
    heap[par] = v; pos[v] = par;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lli", &a[i]);
    add(0); int c = 0, s = 0, best = 0;
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i > k) update(s++);
        dp[i] = a[i] + dp[heap[1]];
        if (ans < dp[i])
            {
                best = i;
                ans = dp[best];
            }
        trace[i] = heap[1];
        add(i);
    }
    printf("%lli\n", ans);
    while (best)
    {
        path[++c] = best;
        best = trace[best];
    }
    printf("%d %d ", c + (c != 0), 0);
    for (int i = c; i >= 1; --i) printf("%d ", path[i]);
}
