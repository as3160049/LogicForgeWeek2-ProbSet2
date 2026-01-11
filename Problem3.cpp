#include<bits/stdc++.h>
using namespace std;

int find_longest_mirror_length(const string& s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Every single character is a palindrome
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Building the dp table
    for(int length = 2; length <= n; ++length) {
        for(int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];       // Characters match so add 2 to length of substring
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);   // Characters don't match, so take max by excluding one end
            }
        }
    }
    return dp[0][n - 1];
}


int main()
{
    string str = "caacbcaab";
    int length = find_longest_mirror_length(str);
    cout << "The length of the longest mirror substring is: " << length << endl;
 return 0;
}