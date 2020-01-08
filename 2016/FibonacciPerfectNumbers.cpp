/**
 * @file   FibonacciPerfectNumbers.cpp
 * @author Seth Traman
 * @date   January 7, 2020
 * 
 * @brief  2016 BPA regionals competition program, rewritten for practice and validation.
 */

#include <array>
#include <iostream>

/**
 * @fn generateFibonacciNumbers
 * 
 * @brief Generates and prints the first 20 numbers of the fibonacci sequence.
 */
static auto generateFibonacciNumbers()
{
	std::array<int, 20> sequence = { 1, 1 };
	
	// generate sequence
	
	for (auto i = 2; i < sequence.size(); ++i)
	{
		sequence[i] = sequence[i - 1] + sequence[i - 2];
	}
	
	// print sequence
	
	for (auto i = 0; i < sequence.size(); ++i)
	{
		std::cout << sequence[i] << " ";
	}
	
	// keep things pretty
	std::cout << std::endl;
}

/**
 * @fn generatePerfectNumbers
 * 
 * @brief Finds and prints all perfect numbers less than 1000.
 */
static auto generatePerfectNumbers()
{
	// check first 1000 positive numbers for perfection
	
	for (auto i = 1; i < 1000; ++i)
	{
		auto sum = 0;
		
		// summate all multiples of potential number
		
		for (auto j = 1; j < i; ++j)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
		
		// if the sum of all multiples equals our number, it is perfect
		
		if (sum == i)
		{
			std::cout << i << " ";
		}
	}
	
	// keep things pretty
	std::cout << std::endl;
}

auto main() -> int
{
	// loop sentry
	auto running = true;
	
	// main loop
	
	while (running)
	{
		// print menu
		
		std::cout
			<< "SPECIAL NUMBER GENERATOR" << std::endl
			<< "1) Fibonacci Sequence" << std::endl
			<< "2) Perfect Number Sequence" << std::endl
			<< "3) Exit" << std::endl;
			
		// gather user input	
		
		unsigned short choice;
		
		std::cout << std::endl << "Please select a menu item: ";
		
		std::cin >> choice;
		
		// act upon user input
		
		switch (choice)
		{
			case 1:
			{
				// print fibonacci sequence
				generateFibonacciNumbers();
				break;
			}
			case 2:
			{
				// print perfect number sequence
				generatePerfectNumbers();
				break;
			}
			case 3:
			{
				// quit
				running = false;
				break;
			}
			default:
			{
				// invalid selection
				std::cout << "Please select a valid menu item." << std::endl;
				break;
			}
		}
		
		// keep things pretty
		std::cout << std::endl;
	}
	
	// bye bye
	std::cout << "Thank you for running the Special Numbers Program :)" << std::endl;
	
	return 0;
}
