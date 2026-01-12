#include<bits/stdc++.h>
using namespace std;

int count_payment_combinations(vector<int> coins, int total_sum) {
    vector<int> dp(total_sum + 1, 0);
    dp[0] = 1; // One way to make sum 0

    for (int coin : coins) {
        for (int j = coin; j <= total_sum; j++) {
            dp[j] += dp[j - coin];
        }
    }
    return dp[total_sum];
}

int main()
{
    vector <int> coins = {1, 2, 3};
    int total_sum = 4;
    int combinations = count_payment_combinations(coins, total_sum);
    cout << "Number of ways to make the payment: " << combinations << endl;
 return 0;
}