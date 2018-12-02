// Day_1.cpp Chronal Calibration 
//For example, if the device displays frequency changes of +1, -2, +3, +1, then starting from a frequency of zero, the following changes would occur:
//Current frequency  0, change of + 1; resulting frequency  1.
//Current frequency  1, change of - 2; resulting frequency - 1.
//Current frequency - 1, change of + 3; resulting frequency  2.
//Current frequency  2, change of + 1; resulting frequency  3.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

// Read the input list and add/subtract from resulting frequency
void CreateFreqList();

int main()
{
	CreateFreqList();
}

void CreateFreqList()
{
	int end_freq = 0;
	int current_line;
	std::string line;
	std::ifstream file("freq_input.txt");

	while (std::getline(file, line))
	{
		if (line.find('+') != std::string::npos)
		{
			line.erase(line.begin());
			current_line = std::stoi(line);
			end_freq += current_line;
		}
		else
		{
			line.erase(line.begin());
			current_line = std::stoi(line);
			end_freq -= current_line;
		}
	}
	std::cout << end_freq << "\n";
}
