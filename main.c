#include "functions.h"

// Recursive function to solve the puzzle
int solve(int t[4][4], int e[16], int p)
{
	int s;

	if (p == 16)
		return (1);
	s = 0;
	while (++s <= 4)
	{
		// Check if the number is valid for placement
		if (chk_dbl(t, p, s) == 0)
		{
			t[p / 4][p % 4] = s;
			// Check if the board remains valid with the new number
			if (chk_case(t, p, e) == 0)
			{
				// Recursively solve for the next position
				if (solve(t, e, p + 1) == 1)
					return (1);
			}
			else
				t[p / 4][p % 4] = 0;
		}
	}
	// No valid solution found for this path
	return (0);
}

// Display the solution board
void display_solution(int t[4][4])
{
	int i, j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			pnum(t[i][j]);
			pchar(' ');
		}
		pchar('\n');
	}
}

int main(int ac, char **av)
{
	int t[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *e;

	// Check input validity
	if (chk(ac, av) == 1)
		return (0);

	// Parse the entry numbers
	e = get_nums(av[1]);

	// Solve the puzzle and display the solution
	if (solve(t, e, 0) == 1)
		display_solution(t);
	else
		pstr("Did not find any solutions\n");

	return (0);
}
