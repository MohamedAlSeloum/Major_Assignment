#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    // Initialize a 2D DP array to store the count of special sequences
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base case: for each value of m, there is 1 way to form a sequence of length 1
    for (int i = 1; i <= m; ++i) {
        dp[i][1] = 1;
    }

    // Fill the DP table for lengths greater than 1
    for (int len = 2; len <= n; ++len) {
        for (int val = 1; val <= m; ++val) {
            // For each value, calculate the count of sequences ending with that value
            // by summing the counts of sequences ending with half or less of that value
            for (int prev = 1; prev <= val / 2; ++prev) {
                dp[val][len] += dp[prev][len - 1];
            }
        }
    }

    // Sum up the counts for all possible ending values to get the total count of special sequences
    int totalCount = 0;
    for (int i = 1; i <= m; ++i) {
        totalCount += dp[i][n];
    }

    return totalCount;
}

void p12_main(void) {
    int m = 5; // Maximum value
    int n = 3; // Length of the sequence

    cout << numberSequence(m, n) << endl;
}
