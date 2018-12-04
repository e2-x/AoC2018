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
#include <unordered_set>
#include <vector>

// Read the input list and add/subtract from resulting frequency
void FindResultFreq();
bool RepeatChangeList(int&, std::unordered_set<int>&);
bool CheckDuplicateFreq(std::unordered_set<int>&, int);

int main()
{
	FindResultFreq();
}
void FindResultFreq()
{
	int current_freq = 0;	// Resulting freq
	int change_freq;		// Amount to change by
	bool found = false;
	std::string line;
	std::ifstream file("freq_input.txt");
	std::unordered_set<int> resultList;
	resultList.insert(current_freq);

	// Part One
	while (std::getline(file, line))
	{
		change_freq = std::stoi(line);
		current_freq += change_freq;
		found = CheckDuplicateFreq(resultList, current_freq);
	}
	printf("Part One: %d \n", current_freq);

	// Part two
	while (!found)
	{
		found = RepeatChangeList(current_freq, resultList);
	}
}

bool CheckDuplicateFreq(std::unordered_set<int> &result_list, int current_freq)
{
	bool duplicate_found = false;

	if (result_list.find(current_freq) != result_list.end())
	{
		printf("Part Two: %d \n", current_freq);
		duplicate_found = true;
	}
	else
	{
		result_list.insert(current_freq);
	}
	return duplicate_found;
}

bool RepeatChangeList(int &current_freq, std::unordered_set<int> &result_list)
{
	// Pick off with the end freq
	int change_freq;	
	int* freq_ptr;
	bool found = false;
	std::string line;
	std::ifstream file("freq_input.txt");

	while (std::getline(file, line))
	{
		change_freq = std::stoi(line);
		current_freq += change_freq;
		found = CheckDuplicateFreq(result_list, current_freq);
		
		if (found)
		{
			break;
		}
	}
	freq_ptr = &current_freq;
	*freq_ptr = current_freq;
	return found;
}
