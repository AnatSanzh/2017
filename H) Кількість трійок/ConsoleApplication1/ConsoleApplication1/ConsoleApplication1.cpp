// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

#define PRECInt unsigned long long int

int main()
{
	PRECInt N, result = 0;
	
	std::cin >> N;
	
	PRECInt maxA = N,
		maxB = (PRECInt)sqrtl(N) + 1,
		maxC = (PRECInt)cbrtl(N) + 1;

	for (PRECInt a = 1; a < maxA; a++)
		for (PRECInt b = 1; b < maxB; b++)
			for (PRECInt c = 1; c < maxC; c++)
				if (a + b * b + c * c*c <= N)
					result++;

    std::cout << result; 
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
