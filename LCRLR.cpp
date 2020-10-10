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
LL dp[1001][1001], da[1001], db[1001];
int fa[1001], fb[1001], a[1001], b[1001], l[1001], m, n;
string s1, s2;

void fact(string s, int a[], int &n, int f[], LL d[])
{
    memset(l, 0, sizeof(l));
    int tmp = 0;
    for (int i = 0; i < s.length(); ++i) if ('0' <= s[i] && s[i] <= '9') tmp = tmp*10 + s[i] - '0';
    else
    {
        d[n] = tmp;
        a[++n] = s[i];
        f[n] = l[s[i]];
        l[s[i]] = n;
        tmp = 0;
    }
    --n;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    getline(cin>>ws, s1); s1 += 'a';
    getline(cin>>ws, s2); s2 += 'a';
    fact(s1, a, n, fa, da);
    fact(s2, b, m, fb, db);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + min(da[i], db[j]);
                LL tmp1 = da[i], tmp2 = db[j];
                int x = i, y = j;
                while (tmp1 != tmp2)
                {
                    if (tmp2 < tmp1)
                    {
                        y = fb[y];
                        tmp2 += db[y];
                    }
                    else
                    {
                        x = fa[x];
                        tmp1 += da[x];
                    }
                    if (!x || !y) break;
                    dp[i][j] = max(dp[i][j], dp[x - 1][y - 1] + min(tmp1, tmp2));
                }
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
        printf("%lli\n", dp[n][m]);

        memset(dp, 0, sizeof(dp)); LL best = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (a[i] != b[j]) dp[i][j] = 0;
                else
                {
                    if (a[i - 1] == b[j - 1])
                    {
                        if (da[i - 1] == db[j - 1]) dp[i][j] = dp[i - 1][j - 1] + min(da[i], db[j]);
                        else dp[i][j] = min(da[i - 1], db[j - 1]) + min(da[i], db[j]);
                    } else dp[i][j] = min(da[i], db[j]);
                }
                best = max(best, dp[i][j]);
            }
        printf("%lli", best);
}
