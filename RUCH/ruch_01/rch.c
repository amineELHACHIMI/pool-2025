#include <unistd.h>

#include <stdlib.h>

// ------------------------- UTILS -------------------------

void	ft_putchar(char c)

{

write(1, &c, 1);

}

void	ft_putstr(char *str)

{

while (*str)

	write(1, str++, 1);

}

int	is_digit_space(char c)

{

return ((c >= '1' && c <= '4') || c == ' ');

}

// ------------------------- PARSE INPUT -------------------------

int	parse_input(char *str, int *clues)

{

int i = 0;


if(!*str || *str==' ')
	return 0;
while (*str)

{

	if (*str >= '1' && *str <= '4')

	{

		if (i >= 16)

			return (0);

		clues[i++] = *str - '0';
str++;
if(*str==' ')
	str++;
	
	
	else if (*str != '\0')

		return (0);
	}
else 
	return 0;
}
return (i == 16);

}

// ------------------------- GRID UTILS -------------------------

int	is_safe(int grid[4][4], int row, int col, int num)

{

int i = 0;

while (i < 4)

{

	if (grid[row][i] == num || grid[i][col] == num)

		return (0);

	i++;

}

return (1);

}

int	count_visible(int *line)

{

int i = 0;

int max = 0;

int visible = 0;



while (i < 4)

{

	if (line[i] > max)

	{

		max = line[i];

		visible++;

	}

	i++;

}

return (visible);

}

void	reverse(int *arr)

{

int tmp;

tmp = arr[0];

arr[0] = arr[3];

arr[3] = tmp;

tmp = arr[1];

arr[1] = arr[2];

arr[2] = tmp;

}

void	copy_col(int grid[4][4], int col, int *out)

{

int i = 0;

while (i < 4)

{

	out[i] = grid[i][col];

	i++;

}

}

// ------------------------- VISIBILITY CHECK -------------------------

int	check_all_views(int grid[4][4], int *clues)

{

int i = 0;

int row[4];



while (i < 4)

{

	// Top view

	copy_col(grid, i, row);

	if (count_visible(row) != clues[i])

		return (0);

	i++;

}

i = 0;

while (i < 4)

{

	// Bottom view

	copy_col(grid, i, row);

	reverse(row);

	if (count_visible(row) != clues[i + 4])

		return (0);

	i++;

}

i = 0;

while (i < 4)

{

	int j = 0;

	while (j < 4)

	{

		row[j] = grid[i][j];

		j++;

	}

	if (count_visible(row) != clues[i + 8])

		return (0);

	i++;

}

i = 0;

while (i < 4)

{

	int j = 0;

	while (j < 4)

	{

		row[j] = grid[i][j];

		j++;

	}

	reverse(row);

	if (count_visible(row) != clues[i + 12])

		return (0);

	i++;

}

return (1);

}

// ------------------------- PRINT GRID -------------------------

void	print_grid(int grid[4][4])

{

int i = 0;

int j;

char c;



while (i < 4)

{

	j = 0;

	while (j < 4)

	{

		c = grid[i][j] + '0';

		ft_putchar(c);

		if (j < 3)

			ft_putchar(' ');

		j++;

	}

	ft_putchar('\n');

	i++;

}

}

// ------------------------- SOLVER (BACKTRACKING) -------------------------

int	solve(int grid[4][4], int *clues, int pos)

{

int row = pos / 4;

int col = pos % 4;

int num = 1;



if (pos == 16)

	return (check_all_views(grid, clues));



while (num <= 4)

{

	if (is_safe(grid, row, col, num))

	{

		grid[row][col] = num;

		if (solve(grid, clues, pos + 1))

			return (1);

		grid[row][col] = 0;

	}

	num++;

}

return (0);

}

// ------------------------- MAIN -------------------------

int	main(int argc, char **argv)

{

int clues[16];

int grid[4][4];

int i = 0;

int j;



if (argc != 2 || !parse_input(argv[1], clues))

{

	ft_putstr("Error\n");

	return (1);

}



while (i < 4)

{

	j = 0;

	while (j < 4)

	{

		grid[i][j] = 0;

		j++;

	}

	i++;

}



if (!solve(grid, clues, 0))

	ft_putstr("Error\n");

else

	print_grid(grid);

return (0);

}
