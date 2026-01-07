#include<bits/stdc++.h>
using namespace std;

//Brute Force approach
int count_ways_to_summit1(int n) {
    if(n == 2) return 2;
    if(n == 1) return 1;
    int ways =  count_ways_to_summit1(n - 1) + count_ways_to_summit1(n - 2);
    return ways;
}

int count_ways_to_summit2(int n) {
    if (n <= 2) return n;

    int prev2 = 1;
    int prev1 = 2;

    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current; 
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    cout << "Using Brute Force: " << count_ways_to_summit1(n) << endl;
    cout << "Using Optimized approach: " << count_ways_to_summit2(n) << endl;
 return 0;
}