/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saatouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:21:28 by saatouam          #+#    #+#             */
/*   Updated: 2025/08/24 20:21:29 by saatouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		parse_input(char *str, int *clues);
void	init_grid(int grid[4][4]);
int		solve(int grid[4][4], int *clues, int pos);
void	print_grid(int grid[4][4]);
int		ft_putstr(char *str);

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
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
}

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	if (argc != 2 || !parse_input(argv[1], clues))
		return (ft_putstr("Error\n"), 1);
	init_grid(grid);
	if (!solve(grid, clues, 0))
		ft_putstr("Error\n");
	else
		print_grid(grid);
	return (0);
}
