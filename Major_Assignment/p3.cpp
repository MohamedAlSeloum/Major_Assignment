#include <iostream>
#include <vector>
#include <algorithm>

#include "problem3.h"

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to compare jobs based on their profits (in descending order)
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

pair<int, int> maxProfitJobs(vector<Job>& jobs) {
    // Sort the jobs in decreasing order of their profits
    sort(jobs.begin(), jobs.end(), compareJobs);

    int maxProfit = 0;
    int numJobsDone = 0;

    // Initialize an array to keep track of whether a deadline has been used or not
    vector<bool> deadlineUsed(jobs.size() + 1, false);

    // Iterate through the sorted jobs
    for (int i = 0; i < jobs.size(); ++i) {
        // Try to schedule the job as late as possible without missing its deadline
        for (int j = min(jobs[i].deadline, (int)jobs.size()); j >= 1; --j) {
            // If the deadline is available, mark it as used and add the profit of the job to the total profit
            if (!deadlineUsed[j]) {
                deadlineUsed[j] = true;
                maxProfit += jobs[i].profit;
                numJobsDone++;
                break;
            }
        }
    }

    return make_pair(numJobsDone, maxProfit);
}

void p3_main(void) {
    vector<Job> jobs = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };

    pair<int, int> result = maxProfitJobs(jobs);

    cout << result.first << " " << result.second << endl;
}
