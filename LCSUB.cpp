#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
int a[1000001], n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    a[n] = -100000;
    int ans = 1, tmp1 = 0, tmp2 = 1;
    for (int i = (a[0] == 0); i < n; ++i)
        if (a[i] == a[i + 1] - 1) ++tmp2;
        else if (a[i] == a[i + 1] - 2)
        {
            if (a[0] == 0) ans = max(ans, tmp1 + tmp2 + 1);
            else ans = max(ans, tmp2);
            tmp1 = tmp2;
            tmp2 = 1;
        }
        else
        {
            if (a[0] == 0) ans = max(ans, tmp1 + tmp2 + 1);
            else ans = max(ans, tmp2);
            tmp1 = 0;
            tmp2 = 1;
        }
        printf("%d", ans);
}
