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
LL dp1[100001], dp2[100001], dp3[100001], a[100001];
int n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lli", &a[i]);
    dp1[2] = max(a[1], a[2]);
    dp2[2] = 2*a[2] + a[1]; dp3[2] = -INF;
    LL best = -INF;
    for (int i = 3; i <= n; ++i)
    {
        dp3[i] = max(dp3[i - 1], dp2[i - 1] + 3*a[i]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + 2*a[i]);
        dp1[i] = max(dp1[i - 1], a[i]);
        best = max(best, dp3[i]);
    }
    printf("%lli", best);
}
