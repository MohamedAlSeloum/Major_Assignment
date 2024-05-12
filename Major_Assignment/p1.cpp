#include <vector>
#include <iostream>
#include <iomanip>

#include "problem1.h"

struct p1_pair {
	int start;
	int end;

	p1_pair(int s, int e) : start(s), end(e) {}
};

std::ostream& operator<<(std::ostream& stream, p1_pair& pair) {
	return stream << "( " << std::setw(2) << pair.start << ", " << std::setw(2) << pair.end << " )";
}

int compare_ints_asc(const void * a, const void * b) { return (*(int*)a - *(int*)b); }

std::vector<p1_pair> maxMeetings(const int length, int start[], int end[]) {
	std::vector<p1_pair> pairs = {};

	// sort both lists in an ascending order

	qsort(start, length, sizeof(int), compare_ints_asc);
	qsort(end, length, sizeof(int), compare_ints_asc);

	for (int i = 0; i < length; i++) {
		pairs.push_back({ start[i], end[i] });
	}

	return pairs;
}

//

void p1_main(void) {
	constexpr int length = 5;

	int p1_start[length] = { 1, 3, 2,  9, 10 };
	int   p1_end[length] = { 2, 6, 5, 12, 13 };

	// print start times
	std::cout << "Start times: [ ";
	for (int i = 0; i < length; i++) {
		std::cout << std::setw(2) << p1_start[i];
		if (i != length - 1) std::cout << ", ";
	}
	std::cout << " ]";
	//

	std::cout << std::endl;

	// print end times
	std::cout << "  End times: [ ";
	for (int i = 0; i < length; i++) {
		std::cout << std::setw(2) << p1_end[i];
		if (i != length - 1) std::cout << ", ";
	}
	std::cout << " ]";
	//

	std::cout << std::endl << std::endl;

	// solve

	auto p1_pairs = maxMeetings(length, p1_start, p1_end);

	// print

	std::cout << "Solution: " << std::endl << std::endl;

	for (int i = 0; i < length; i++) {
		std::cout << p1_pairs[i] << std::endl;
	}
}
