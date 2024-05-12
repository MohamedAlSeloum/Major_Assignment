#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& books, int students, int maxPages) {
    int sum = 0;
    int count = 1; // At least one student will get one book
    for (int i = 0; i < books.size(); ++i) {
        if (books[i] > maxPages) {
            return false; // If any book cannot be assigned to any student
        }
        sum += books[i];
        if (sum > maxPages) {
            count++;
            sum = books[i];
        }
        if (count > students) {
            return false; // If more students are required
        }
    }
    return true; // Allocation is possible
}

int minPages(vector<int>& books, int students) {
    int n = books.size();
    if (n < students) {
        return -1; // Not enough books for each student
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += books[i];
    }

    int low = *max_element(books.begin(), books.end());
    int high = total;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(books, students, mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

void p11_main(void) {
    vector<int> books = { 12, 34, 67, 90 };
    int students = 2;

    cout << minPages(books, students) << endl;
}
