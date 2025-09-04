/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grind_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saatouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:19:50 by saatouam          #+#    #+#             */
/*   Updated: 2025/08/24 20:19:56 by saatouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_safe(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	print_row(int row[4])
{
	int		j;
	char	c;

	j = 0;
	while (j < 4)
	{
		c = row[j] + '0';
		ft_putchar(c);
		if (j < 3)
			ft_putchar(' ');
		j++;
	}
}

void	print_grid(int grid[4][4])
{
	int	i;
	int	row[4];
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
		print_row(row);
		ft_putchar('\n');
		i++;
	}
}
