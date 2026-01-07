#include<bits/stdc++.h>
using namespace std;

bool can_balance_scales(vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    int n = arr.size();

    vector<bool> dp(target+1, false);
    dp[0] = true;
    
    for (int num : arr) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

int main()
{
    vector<int> weights = {1, 5, 11, 5};
    if (can_balance_scales(weights)) {
        cout << "The scales can be balanced." << endl;
    } else {
        cout << "The scales cannot be balanced." << endl;
    }
 return 0;
}