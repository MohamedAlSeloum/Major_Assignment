#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair of numbers
struct Pair {
    int first;
    int second;
};

// Function to compare pairs based on their second number (in increasing order)
bool compare_pairs(const Pair& a, const Pair& b) {
    return a.second < b.second;
}

int longest_chain(vector<Pair>& pairs) {
    // Sort the pairs based on their second number in increasing order
    sort(pairs.begin(), pairs.end(), compare_pairs);

    int n = pairs.size();
    vector<int> dp(n, 1); // Initialize dp array with 1, as each pair forms a chain of length 1

    // Iterate through the sorted pairs
    for (int i = 1; i < n; ++i) {
        // Find the maximum length of the chain that can be formed ending at the current pair
        for (int j = 0; j < i; ++j) {
            if (pairs[j].second < pairs[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum length of the chain
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

void p5_main(void) {
    vector<Pair> pairs = { {5, 24}, {15, 25}, {27, 40}, {50, 60} };

    cout << longest_chain(pairs) << endl;
}
