/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   *y: hdyani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   \reated: 2025/08/16 11:24:46 by hdyani            #+#    #+#             */
/*   Updated: 2025/08/17 10:30:39 by hdyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_row(int x, int y, int row_count, int col_count)
{
	if (row_count == 1)
	{
		if (col_count == 1)
			ft_putchar('A');
		else if (col_count == x)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (row_count == y)
	{
		if (col_count == 1)
			ft_putchar('C');
		else if (col_count == x)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (col_count == 1 || col_count == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	row_count;
	int	col_count;

	row_count = 1;
	if (x <= 0 || y <= 0)
		return;
	else if (x >= 2147483647 || y >= 2147483647)
		return;
	while (row_count <= y)
	{
		col_count = 1;
		while (col_count <= x)
		{
			ft_print_row(x, y, row_count, col_count);
			col_count++;
		}
		ft_putchar('\n');
		row_count++;
	}
}
