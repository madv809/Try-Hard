#define ll long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>

using namespace std;
const ll INF = 9999999999;
ll dp[31][60000] ,pow[11], cost[31];
bool fav[11][31], vist[31][60000];
int m, n;

ll go (int v, int state)
{
    if (v == m)
    {
        if (state == pow[n] - 1) return 0;
        return INF;
    }
    if (vist[v][state]) return dp[v][state];
    ll &ans = dp[v][state], tmp = state;
    vist[v][state] = 1;
    ans = go(v + 1, state);
    for (int i = 0; i < n; ++i)
    {
        if (fav[i][v])
        {
            if (state/pow[i]%3 == 2) return ans;
            tmp += pow[i];
        }
    }
    ans = min(ans, cost[v] + go(v + 1, tmp));
    return ans;
}

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) scanf("%lli", &cost[i]);
    string s;
    for (int i = 0; i < n; ++i)
    {
        getline(cin >> ws, s);
        stringstream ss(s);
        ll x;
        while (ss >> x) fav[i][x - 1] = 1;
    }
    pow[0] = 1;
    for (int i = 1; i < 11; ++i) pow[i] = pow[i-1]*3;
    ll best = go(0, 0);
    if (best < INF) printf("%lli", best);
    else printf("-1");
}
