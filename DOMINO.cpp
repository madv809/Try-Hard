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
int t;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        string s;
        getline(cin >> ws, s);
        int i = 0;
        if (s.length() == 1)
        {
            if (s == "A") printf("YES\n");
            else printf("NO\n");
            i = 100000000;
        }         int a = s.length();
        for (; i < s.length() - 1;)
        {
            if (s[i] == 'A')
            {
                if (s[i + 1] == 'A') i += 1;
                else i += 2;
            } else if (s[i] == 'B')
            {
                if (s[i + 1] == 'B')
                {
                    printf("NO\n");
                    i = 100000000;
                    continue;
                }
                else i += 2;
            }
        }
        if (i == s.length()) printf("YES\n");
        else if (i == s.length() - 1)
        {
            if (s[i] == 'A') printf("YES\n");
            else printf("NO\n");
        }
    }
}
