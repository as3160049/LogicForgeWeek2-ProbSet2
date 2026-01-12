#include <bits/stdc++.h>
using namespace std;

int calculate_minimum_speed(vector<int>& piles, long long k) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;
        }

        if (hours <= k) {
            // Speed is sufficient so try lower
            answer = mid;
            high = mid - 1;
        } else {
            // Speed slow so increase it
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    long long k = 8;
    int minSpeed = calculate_minimum_speed(piles, k);
    cout << "Minimum speed to finish piles in " << k << " hours: " << minSpeed << endl;
    return 0;
}
