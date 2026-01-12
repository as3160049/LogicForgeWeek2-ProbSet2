#include <bits/stdc++.h>
using namespace std;

int min_cancelled_bookings(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort by end time
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) {
             return a[1] < b[1];
         });

    int removals = 0;
    int lastEnd = intervals[0][1];

    // Traverse intervals
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < lastEnd) {
            // Overlap so remove current interval
            removals++;
        } else {
            // No overlap so keep it
            lastEnd = intervals[i][1];
        }
    }

    return removals;
}

int main() {
    vector<vector<int>> bookings = {{1, 3}, {2, 4}, {3, 5}, {6, 7}};
    int result = min_cancelled_bookings(bookings);
    cout << "Minimum number of bookings to cancel: " << result << endl;
    return 0;
}
