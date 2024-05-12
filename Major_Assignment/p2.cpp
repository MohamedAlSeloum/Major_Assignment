#include <iostream>
#include <vector>
#include <iomanip>
#include "problem2.h"

struct p2_job {
	int id;

	int deadline;
	int profit;

	p2_job(int id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

std::ostream& operator<<(std::ostream& stream, p2_job& job) {
	return stream << "( ID: " << std::setw(2) << job.id << ", Deadline: " << std::setw(2) << job.deadline << ", Profit: " << std::setw(2) << job.profit << " )";
}

int compare_jobs_desc(const void* a, const void* b) { return (((p2_job*)b)->profit - ((p2_job*)a)->profit); }

std::vector<int> JobScheduling(const int length, p2_job jobs[]) {
	if (length == 0) return { 0, 0 };

	if (length == 1) {
		if (jobs[0].deadline <= length) return { 1, jobs[0].profit };
		else return { 0, 0 };
	}
	

	// sort in a descending order
	std::qsort(jobs, length, sizeof(p2_job), compare_jobs_desc);

	int deadline = 0;
	int profits = 0;
	int number = 0;
	std::vector<p2_job> selected_jobs{};

	for (int i = 0; i < length; i++) {
		//if (deadline > length) break;

		if (deadline + jobs[i].deadline > length) continue;

		deadline += jobs[i].deadline;
		profits += jobs[i].profit;
		number++;
	}

	return { number, profits };
}


void p2_main(void) {
	constexpr int length = 5;

	p2_job jobs[length] = { { 1, 3, 12 }, { 2, 2, 4 }, { 3, 6, 10 }, { 4, 3, 4 }, { 5, 5, 13 } };

	std::cout << "Jobs: " << std::endl << std::endl;

	for (int i = 0; i < length; i++) {
		std::cout << jobs[i] << std::endl;
	}

	std::cout << std::endl;

	auto result = JobScheduling(length, jobs);

	std::cout << "Solution" << std::endl << std::endl;

	std::cout << "Number of jobs: " << result[0] << std::endl;
	std::cout << "Total profits: " << result[1] << std::endl;
}
