#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "problem4.h"

using namespace std;

// Structure to represent a pair
struct p4_pair {
    int first, second;
};

std::ostream& operator<<(std::ostream& stream, p4_pair& pair) {
    return stream << "( " << std::setw(2) << pair.first << ", " << std::setw(2) << pair.second << " )";
}

// Comparator function to sort pairs based on the second value
bool compare_pairs(const p4_pair& a, const p4_pair& b) {
    return a.second < b.second;
}

// Function to find the length of the longest chain of pairs
int longest_chain(vector<p4_pair>& pairs) {
    // Sort the pairs based on the second value
    sort(pairs.begin(), pairs.end(), compare_pairs);

    int n = pairs.size();
    // dp[i] stores the length of the longest chain ending at pairs[i]
    vector<int> dp(n, 1);

    // Iterate through each pair
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // If the second value of pairs[j] is less than the first value of pairs[i],
            // then we can extend the chain
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

void p4_main(void) {
    constexpr int length = 6;

    std::vector<p4_pair> pairs = { { 1, 3 }, { 4, 5 }, { 6, 10 }, { 11, 13 }, { 5, 4 }, { 2, 6 } };

    std::cout << "Pairs" << std::endl << std::endl;

    for (auto& pair : pairs) {
        std::cout << pair << std::endl;
    }

    std::cout << std::endl;

    auto result = longest_chain(pairs);

    std::cout << "Result: " << result << std::endl;
}
