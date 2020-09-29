#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const LL MOD = 1000000007;
int dp[51][51], a[51];

int go (int l, int r)
{
    int &ans = dp[l][r];
    if (ans != -1) return ans;
    if (l == r) return ans = 1;
    if (l > r) return ans = 0;
    ans = 1 + go(l + 1, r);
    for (int i = l + 1; i <= r; ++i)
        if (a[l] == a[i]) ans = min(ans, go(l + 1, i - 1) + go(i, r));
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, n - 1));
}
