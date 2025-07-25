#include <cstdio>
using namespace std;
int n, ans;
int a[1005];
int dp[1005][1005];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j > 0)
                dp[i][j] = dp[i - 1][j - 1];
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == i - j));
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}
