#include <iostream>
#include <string>
#include <vector>

#include "problem1.h"
#include "problem2.h"
#include "problem3.h"
#include "problem4.h"
#include "problem5.h"
#include "problem6.h"
#include "problem7.h"
#include "problem8.h"
#include "problem9.h"
#include "problem10.h"
#include "problem11.h"
#include "problem12.h"

int main(void) {
	int problem = 0;
	std::string str_choice{};

	ask_problem:

	std::cout << "Enter the number of the problem (1 - 12): ";
	std::cin >> problem;

	if (problem < 1 || problem > 12) {
		std::cout << "Invalid number; please try again." << std::endl;
		goto ask_problem;
	}

	switch (problem) {
	case 1: p1_main(); break;
	case 2: p2_main(); break;
	case 3: p3_main(); break;
	case 4: p4_main(); break;
	case 5: p5_main(); break;
	case 6: p6_main(); break;
	case 7: p7_main(); break;
	case 8: p8_main(); break;
	case 9: p9_main(); break;
	case 10: p10_main(); break;
	case 11: p11_main(); break;
	case 12: p12_main(); break;
	}

	ask_again:

	std::cout << "Run again (y/n)? ";
	std::cin >> str_choice;

	if (str_choice == "y" || str_choice == "yes") {
		goto ask_problem;
	}
	else if (str_choice == "n" || str_choice == "no") {
		return 0;
	}
	else {
		std::cout << "Couldn't get that; please try again." << std::endl;
		goto ask_again;
	}

	return 0;
}