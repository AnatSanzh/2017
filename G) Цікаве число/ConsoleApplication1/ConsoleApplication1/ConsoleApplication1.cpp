// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

int digitSum(std::vector<char> &str) {
	int res = 0;
	size_t len = str.size();

	for (auto it = str.begin(); it != str.end(); it++) {
		res += (*it) - '0';
	}

	return res;
}

void addBigInts(std::vector<char> &result, const std::vector<char> &additor)
{
	// Some helper variables
	auto min_size = additor.size();
	auto max_size = result.size();

	char carry = 0;

	auto add_digits = [](char lhs, char rhs, char &carry)
	{
		auto adder = lhs + rhs + carry;
		carry = adder / 10;
		return adder % 10;
	};

	for (int cnt = 0; cnt < min_size; ++cnt)
	{
		result[cnt] = add_digits(result[cnt] - '0', additor[cnt] - '0', carry) + '0';
	}

	for (int cnt = min_size; carry && cnt < max_size; ++cnt)
	{
		result[cnt] = add_digits(result[cnt] - '0', 0, carry) + '0';
	}

	if (carry)
	{
		result.push_back(carry + '0');
	}
}

void outputVectorOfChar(const std::vector<char> &v) {
	for (auto it = v.rbegin(); it!=v.rend(); it++)
		std::cout << *it;
}

int main()
{
	int N;

	std::cin >> N;

	std::vector<char> result;
	{
		std::string tempStr = std::to_string(N);
		result = std::vector<char>(tempStr.rbegin(), tempStr.rend());
	}
	
	std::vector<char> additor = result;


	do {
		addBigInts(result, additor);
	} while (digitSum(result) != N);

	outputVectorOfChar(result);
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
