// A Backtracking program in C
// to solve Sudoku problem
// Tomado de https://www.geeksforgeeks.org/sudoku-backtracking-7/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>

// UNASSIGNED is used for empty
// cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of
// Sudoku grid. The size will be NxN
#define N 9

// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(int grid[N][N], int row,
			int col, int num);

/* Takes a partially filled-in grid
and attempts to assign values to
all unassigned locations in such
a way to meet the requirements
for Sudoku solution (non-duplication
across rows, columns, and boxes) */
bool SolveSudoku(int grid[N][N])
{
	int row, col;

	//Cconsider digits 1 to 9
	for (int num = 1; num <= 9; num++)
	{
		
		// Check if looks promising
		if (isSafe(grid, row, col, num))
		{
			
			// Make tentative assignment
			grid[row][col] = num;

			// Return, if success, yay!
			if (SolveSudoku(grid))
				return true;

			// Failure, unmake & try again
			grid[row][col] = UNASSIGNED;
		}
	}

	// This triggers backtracking
	return false;
}

/* Returns a boolean which indicates
whether an assigned entry
in the specified row matches the
given number. */
bool UsedInRow(
	int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates
whether an assigned entry
in the specified column matches
the given number. */
bool UsedInCol(
	int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates
whether an assigned entry
within the specified 3x3 box
matches the given number. */
bool UsedInBox(
	int grid[N][N], int boxStartRow,
	int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (
				grid[row + boxStartRow]
				[col + boxStartCol] ==
								num)
				return true;
	return false;
}

/* Returns a boolean which indicates
whether it will be legal to assign
num to the given row, col location. */
bool isSafe(
	int grid[N][N], int row,
	int col, int num)
{
	
	/* Check if 'num' is not already placed
	in current row, current column and
	current 3x3 box */
	return !UsedInRow(grid, row, num)
		&& !UsedInCol(grid, col, num)
		&& !UsedInBox(grid, row - row % 3,
						col - col % 3, num)
		&& grid[row][col] == UNASSIGNED;
}


/* Driver Program to test above functions */
int main()
{
	int grid[N][N];
	char ch [100];
	char filename [20];
	// rowN
	FILE *ptr;

	scanf("%s", filename);

	if ((ptr = fopen(filename, "r")) == NULL) {
		printf("error reading file");
	}

	fgets(ch, 100, ptr);

	int length = strlen(ch);
	int index = 0;

	for (int j = 0; j < 9; j++) {
		for (int i = index; i < index + 9; i++) {
			grid[j][i] = ch[i] - '0';
		}
		index = index + 9;
	}
	// si se meten bien a la matriz


	if (SolveSudoku(grid) == true)
		printf("Success");
	else
		printf("No solution exists");
	// saber porque sale que no tiene solucion :(
	fclose(ptr);

	return 0;
}
