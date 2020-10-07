#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;
const int INF = 1000000007;
int dp[2001][2001], trace[2001][2001], n;
bool pan[2001][2001];

int go(int l, int r)
{
    if (l > r) return 0;
    int &ans = dp[l][r];
    if (ans != -1) return ans;
    ans = INF;
    for (int i = l; i <= r; ++i) if (pan[l][i])
    {
        if (ans > 1 + go(i + 1, r))
        {
            ans = 1 + go(i + 1, r);
            trace[l][r] = i + 1;
        }
    }
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    string s;
    getline(cin>>ws, s);
    for (int i = 0; i < n; ++i) pan[i][i] = 1;
    for (int i = 0; i <= n - 1; ++i) pan[i][i + 1] = (s[i] == s[i + 1]);
    for (int k = 2; k < n; ++k)
        for (int i = 0; i + k < n; ++i) pan[i][i + k] = (s[i] == s[i + k] && pan[i + 1][i + k - 1]);
    memset(dp, -1, sizeof(dp));
    int best = go(0, n - 1);
    printf("%d\n", best);
    trace[n][n - 1] = n + 1;
    int tmp = 0, x = trace[0][n - 1];
    while (x != n + 1)
    {
        for (int i = tmp; i < x; ++i) cout << s[i];
        cout << endl;
        tmp = x;
        x = trace[x][n - 1];
    }
}
