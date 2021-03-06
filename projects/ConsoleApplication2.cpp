// ConsoleApplication2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ratio>
#include <conio.h>
#include <Windows.h>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h> /* time */
#include <chrono>

using namespace std;
using namespace std::chrono;
unsigned y,x,losowe;


int main()
{
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	std::vector<int> myvector;
	for (int i = 1; i <= 5; i++)
	{
		myvector.push_back(i);
	}
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	{
		std::cout << ' ' << *it;
	}

	do{
		std::cout << '\n';
		std::cout << "1.PUSH_BACK";
		std::cout << '\n';
		std::cout << "2.POP_BACK";
		std::cout << '\n';
		std::cout << "3.STD_SORT";
		std::cout << '\n';
		std::cout << "4.CLEAR";
		std::cout << '\n';
		std::cout << "5.10000xRAND PUSH_BACK";
		std::cout << '\n';
		if (!myvector.empty())
		{
			std::cout << '\n';
			std::cout << '\n';
			std::cout << "First:";
			std::cout << myvector.front();
			std::cout << '\n';
			std::cout << "Last:";
			std::cout << myvector.back();
			std::cout << '\n';
			std::cout << "Size:";
			std::cout << myvector.size();
			std::cout << '\n';
			
		}
		std::cin >> y;
		switch (y)
		{
		case 1:
		{
			std::cin >> x;
			myvector.push_back(x);
		}
			break;
		case 2:
		{
			if (!myvector.empty())
				myvector.pop_back();
		}
			break;
		case 3:
		{
			t1 = high_resolution_clock::now();
			std::sort(myvector.begin(), myvector.end());
			t2 = high_resolution_clock::now();
		}
			break;
		case 4:
		{
			myvector.clear();
		}
			break;
		case 5:
		{
			srand(time(NULL));
			/* initialize random seed: */
			/* generate secret number between 1 and 10: */
			for (int i = 0; i < 10000; i++)
			{
				losowe = rand() % 1000000 + 1;
				myvector.push_back(losowe);
			}
		}
			break;
		default:
		{
			std::cin >> y;
		}
			break;
		}
		system("cls");
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			std::cout << ' ' << *it;
		}
		std::cout << '\n';
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		auto int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
		
		if (y == 3)
		{
			std::cout << "It took me " << time_span.count() << " seconds.";
			std::cout << std::endl;
			std::cout << fixed << "It took me " << int_ms.count() << " nanoseconds.";
			std::cout << std::endl;
		}
	} while (true);
	_getch();

	return 0;
}