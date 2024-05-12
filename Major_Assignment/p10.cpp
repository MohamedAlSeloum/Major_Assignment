#include <iostream>
#include <vector>

#include "problem10.h"

using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0, count = 0;
    int result;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            result = arr1[i];
            i++;
        }
        else {
            result = arr2[j];
            j++;
        }
        count++;
        if (count == k) {
            return result;
        }
    }

    while (i < n) {
        result = arr1[i];
        i++;
        count++;
        if (count == k) {
            return result;
        }
    }

    while (j < m) {
        result = arr2[j];
        j++;
        count++;
        if (count == k) {
            return result;
        }
    }

    return result; // In case k is greater than the total number of elements in both arrays
}

void p10_main(void) {
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int k = 5;

    cout << kthElement(arr1, arr2, k) << endl;
}
