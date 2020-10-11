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
const LL INF = 100000000000009;
LL sum[200001], a[200001], b[200001], c[3];
vector <LL> dpr, dpl;
int n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    dpr.resize(n + 1); dpl.resize(n + 1);
    c[0] = 0; c[1] = c[2] = INF;
    dpr[0] = dpl[0] = -INF;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lli", &a[i]);
        b[n - i + 1] = a[i];
        sum[i] = sum[i - 1] + a[i];
        dpr[i] = max(dpr[i - 1], sum[i] - c[i%3]);
        c[i%3] = min(c[i%3], sum[i]);
    }
    c[0] = 0; c[1] = c[2] = INF;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + b[i];
        dpl[i] = max(dpl[i - 1], sum[i] - c[i%3]);
        c[i%3] = min(c[i%3], sum[i]);
    }
    reverse(dpl.begin() + 1, dpl.end());
    LL best = -INF;
    for (int i = 3; i <= n - 3; ++i) best = max(best, dpr[i] + dpl[i + 1]);
    printf("%lli", best);
}
