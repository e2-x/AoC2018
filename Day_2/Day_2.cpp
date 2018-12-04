// Day 2 - Inventory Management System
//For example, if you see the following box IDs :
//abcdef contains no letters that appear exactly two or three times.
//bababc contains two a and three b, so it counts for both.
//abbcde contains two b, but no letter appears exactly three times.
//abcccd contains three c, but no letter appears exactly two times.
//aabcdd contains two a and two d, but it only counts once.
//abcdee contains two e.
//ababab contains three a and three b, but it only counts once.
// Need to count number of occurences for each letter
// Need to keep count of of lines with 2 or 3 occurences of a letter
// Need to multiply lines to find product

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

void FindRepeatInLine(std::string&, int&, int&);

int main()
{
	int diffChar = 0, currentChar = 0, diffCharID = 0;
	int twiceCount = 0, thriceCount = 0;
	int length, checkSum;
	bool found = false;
	char startChar;
	std::string line;
	std::ifstream file("day_two_inputs.txt");
	std::vector<int> lineTotals;
	std::vector<std::string> boxID;

	// Find occurences per line
	while (std::getline(file, line))
	{
		// Part One
		FindRepeatInLine(line, twiceCount, thriceCount);
		boxID.push_back(line);
	}

	checkSum = twiceCount * thriceCount;
	printf("Part One: %d \n", checkSum);

	// Part Two
	length = boxID[0].length();
	for (int i = 0; i < boxID.size(); i++)
	{
		for (int j = i + 1; j < boxID.size(); j++)
		{
			std::cout << "\nCurrently checking: " << boxID[i] << " against " << boxID[j] << "\n";
			while (!found && diffChar < 2)
			{
				std::cout << "Currently checking char: " << boxID[i][currentChar] << " against " << boxID[j][currentChar] << "\n";
				if (boxID[i][currentChar] != boxID[j][currentChar])
				{
					diffCharID = currentChar;
					diffChar++;
				}
				if (currentChar < length)
				{
					currentChar++;
				}
				if (diffChar < 2 && currentChar == length - 1)
				{
					std::string match = boxID[i];
					match.erase(match.begin() + diffCharID);
					std::cout << "Match found: " << boxID[i] << " and " << boxID[j] << "\n";
					std::cout << "Answer is: " << match;
					found = true;
					i = boxID.size() - 1;
				}
			}
			if (found)
				break;

			currentChar = 0;
			diffChar = 0;
		}
	}
	system("pause");
}

void FindRepeatInLine(std::string &line, int &twice, int &thrice)
{
	int current_count = 0;
	int* count_ptr;
	bool twiceFound = false, thriceFound = false;

	for (int i = 0; i < line.length(); i++)
	{
		for (int j = 0; j < line.length(); j++)
		{
			if (line[i] == line[j])
			{
				current_count++;
			}
			if (!thriceFound && current_count == 3)
			{
				count_ptr = &thrice;
				*count_ptr = thrice + 1;
				thriceFound = true;
				break;
			}
			else if (!twiceFound && j == line.length() - 1 && current_count == 2)
			{
				count_ptr = &twice;
				*count_ptr = twice + 1;
				twiceFound = true;
				break;
			}
		}
		// Reset
		current_count = 0;
	}
} 
