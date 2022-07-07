#include <iostream>
using namespace std;

int solve(string s, string v) {
    int MAX = 1005;
    int m = s.length() , n = v.length();
 
    int dp[m+1][n+1];
 
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;
 
    // S string is empty
    for (int i = 0; i <= n; i++)
        dp[0][i] = MAX;
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = s[i-1];
            int k;
            for (k = j-1; k >= 0; k--)
                if (v[k] == ch)
                    break;
            if (k == -1)
                dp[i][j] = 1;
            else
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
        }
    }
 
    int ans = dp[m][n];
    if (ans >= MAX)
        ans = -1;
 
    return ans;
}

int main() {
    string s, v;
    cin >> s >> v;

    cout << solve(s, v);
}