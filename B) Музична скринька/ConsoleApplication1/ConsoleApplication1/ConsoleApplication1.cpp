// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int GCD(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int LCM(int a, int b) {
	return a / GCD(a, b) * b;
}

int LCM(int size, int arr[]) {
	int result = LCM(arr[0], arr[1]);

	for (int i = 2; i < size; i++)
		result = LCM(result, arr[i]);

	return result;
}

int main()
{
	int size;

	std::cin >> size;

	int *arr = new int[size];

	for (int i = 0; i < size; i++)
		std::cin >> arr[i];

    std::cout << LCM(size, arr);

	delete[] arr;
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
