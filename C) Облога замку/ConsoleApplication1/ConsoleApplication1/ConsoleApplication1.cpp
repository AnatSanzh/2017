// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int getHeight(float distance, const int horizontalSpeed) {
	distance /= horizontalSpeed;
	return roundf(490.5*distance*distance);
}

int main()
{
	int horizontalSpeed, N;

	std::cin >> horizontalSpeed >> N;

	std::vector<int> output;
	output.reserve(N);

	float temp;
	for (;N > 0; N--) {
		std::cin >> temp;

		output.push_back(getHeight(temp, horizontalSpeed));
		std::push_heap(output.begin(), output.end());
	}

	std::sort_heap(output.begin(), output.end());

	for (auto it = output.begin(); it != output.end(); ++it) {
		std::cout << (*it)*0.01 << std::endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
