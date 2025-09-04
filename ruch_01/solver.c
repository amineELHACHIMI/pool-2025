/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saatouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:20:59 by saatouam          #+#    #+#             */
/*   Updated: 2025/08/25 09:35:35 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int		count_visible(int *line);
void	reverse(int *arr);
void	copy_col(int grid[4][4], int col, int *out);
int		is_safe(int grid[4][4], int row, int col, int num);

int	check_columns(int grid[4][4], int *clues)
{
	int	i;
	int	row[4];

	i = 0;
	while (i < 4)
	{
		copy_col(grid, i, row);
		if (count_visible(row) != clues[i])
			return (0);
		reverse(row);
		if (count_visible(row) != clues[i + 4])
			return (0);
		i++;
	}
	return (1);
}

int	check_rows(int grid[4][4], int *clues)
{
	int	row[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row[j] = grid[i][j];
			j++;
		}
		if (count_visible(row) != clues[i + 8])
			return (0);
		reverse(row);
		if (count_visible(row) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}

int	check_all_views(int grid[4][4], int *clues)
{
	return (check_columns(grid, clues) && check_rows(grid, clues));
}

int	solve(int grid[4][4], int *clues, int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_all_views(grid, clues));
	row = pos / 4;
	col = pos % 4;
	num = 1;
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
