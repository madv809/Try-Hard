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
const int maxn = 10001;
int heap[maxn], pos[maxn], nheap, n, m, k;
vector <int> r[maxn], l[maxn], a[maxn], bl[maxn], br[maxn];
LL di[maxn], d1[maxn], d2[maxn], d3[maxn];
bool vist[maxn];

void update(int v)
{
    int child = pos[v];
    if (child == 0) child = ++nheap;
    int par = child/2;
    while (par != 0 && di[heap[par]] > di[v])
    {
        heap[child] = heap[par];
        pos[heap[child]] = child;
        child = par; par /= 2;
    }
    heap[child] = v;
    pos[v] = child;
}

int pop()
{
    int res = heap[1];
    int v = heap[nheap--], par = 1, child = par*2;
    while (child <= nheap)
    {
        if (child < nheap && di[heap[child]] > di[heap[child + 1]]) ++child;
        if (di[v] <= di[heap[child]]) break;
        heap[par] = heap[child];
        pos[heap[par]] = par;
        par = child; child *= 2;
    }
    heap[par] = v;
    pos[v] = par;
    return res;
}

void reset(int k)
{
    memset(pos, 0, sizeof(pos));
    memset(vist, 0, sizeof(vist));
    for (int i = 1; i <= n; ++i) di[i] = INF;
    di[k] = 0;
}

void findd(int k, vector <int> c[], vector <int> v[], LL d[])
{
    reset(k);
    update(k);
    while (nheap)
    {
        int u = pop();
        vist[u] = 1;
        for (int i = 0; i < v[u].size(); ++i) if(!(vist[v[u][i]]) && di[v[u][i]] > di[u] + c[u][i])
        {
            di[v[u][i]] = di[u] + c[u][i];
            update(v[u][i]);
        }
    }
    for (int i = 1; i <= n; ++i) d[i] = di[i];
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    int u, v, ai, bi;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d%d", &u, &v, &ai, &bi);
        r[u].push_back(v); l[v].push_back(u);
        a[v].push_back(ai); br[u].push_back(bi); bl[v].push_back(bi);
    }

    findd(1, br, r, d1);
    findd(k, a, l, d2);
    findd(n, bl, l, d3);

    LL best = INF;
    for (int i = 1; i <= n; ++i) if (d1[i] + d2[i] < 60 && d1[i] + d3[i] < best) best = d1[i] + d3[i];
    printf("%lli", best);
 }
