#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline;
    int profit;
};

// DSU finding
int findParent(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x], parent);
}

vector<int> maximize_freelance_profit(vector<int>& deadlines, vector<int>& profits) {
    int n = deadlines.size();
    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) {
        jobs[i] = {deadlines[i], profits[i]};
    }

    // Sort jobs by profit (descending)
    sort(jobs.begin(), jobs.end(),
         [](Job& a, Job& b) {
             return a.profit > b.profit;
         });

    // Find max deadline
    int maxDeadline = 0;
    for (auto& job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    // Initialize DSU
    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++)
        parent[i] = i;

    int totalJobs = 0;
    int totalProfit = 0;

    // Schedule jobs
    for (auto& job : jobs) {
        int availableSlot = findParent(job.deadline, parent);

        if (availableSlot > 0) {
            // Assign job
            totalJobs++;
            totalProfit += job.profit;

            // Mark slot as occupied
            parent[availableSlot] = availableSlot - 1;
        }
    }

    return {totalJobs, totalProfit};
}

int main() {
    vector<int> deadlines = {2, 1, 2, 1, 3};
    vector<int> profits = {100, 19, 27, 25, 15};

    vector<int> result = maximize_freelance_profit(deadlines, profits);
    cout << "Total Jobs: " << result[0] << ", Total Profit: " << result[1] << endl;

    return 0;
}
