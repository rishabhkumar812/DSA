#include <bits/stdc++.h>
using namespace std;
#define debug true

//To find is s3 is an interleaving of s1 and s2
//Dynamic programming (O(mn) time and O(mn) space complexity)
bool isInterleave(string s1, string s2, string s3)
{
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

    if ((len1 + len2) != len3)
        return false;

    bool dp[len1 + 1][len2 + 1];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < len1 + 1; ++i)
        for (int j = 0; j < len2 + 1; ++j)
        {
            if (i == 0 and j == 0)
                dp[i][j] = true;

            else if (i == 0)
            {
                if (s2[j - 1] == s3[j - 1])
                    dp[i][j] = dp[i][j - 1];
            }

            else if (j == 0)
            {
                if (s1[i - 1] == s3[i - 1])
                    dp[i][j] = dp[i - 1][j];
            }

            else if (s1[i - 1] == s3[i + j - 1] and s2[j - 1] == s3[i + j - 1])
                dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);

            else if (s1[i - 1] == s3[i + j - 1])
                dp[i][j] = dp[i - 1][j];

            else if (s2[j - 1] == s3[i + j - 1])
                dp[i][j] = dp[i][j - 1];
        }

    return dp[len1][len2];
}

int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    if (debug)
    {
        cout << "s1=" << s1 << endl;
        cout << "s2=" << s2 << endl;
        cout << "s3=" << s3 << endl;
    }
    cout << ((isInterleave(s1, s2, s3)) ? "true" : "false");
}