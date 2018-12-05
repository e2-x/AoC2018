// Day 3 - No Matter How You Slice It
// Each claim's rectangle is defined as follows:
// The number of inches between the left edge of the fabric and the left edge of the rectangle.
// The number of inches between the top edge of the fabric and the top edge of the rectangle.
// The width of the rectangle in inches.
// The height of the rectangle in inches.
#include <stdio.h>
#include <stdlib.h>

int main()
{
	bool collisionFree = true;
	char* arr = (char*)calloc(1000, 1000);
	FILE* f = fopen("day_3_input.txt", "r");
	int ID, x, y, h, w, count = 0;
	while (EOF != fscanf(f, "#%d @ %d,%d: %dx%d\n", &ID, &x, &y, &w, &h))
	{
		for (int i = x; i < x + w; i++)
		{
			for (int j = y; j < y + h; j++)
			{
				if (1 == arr[i * 1000 + j]++)
					count++;
			}
		}
	}

	printf("Part One: %d\n", count);
	f = fopen("day_3_input.txt", "r");
	while (EOF != fscanf(f, "#%d @ %d,%d: %dx%d\n", &ID, &x, &y, &w, &h))
	{
		collisionFree = true;
		for (int i = x; i < x + w; i++)
		{
			for (int j = y; j < y + h; j++)
			{
				if (arr[i * 1000 + j] > 1)
				{
					collisionFree = false;
					i = (x + w) - 1;
					break;
				}
			}
		}
		if (collisionFree)
		{
			printf("Part Two: %d", ID);
		}
	}
	system("pause");
}