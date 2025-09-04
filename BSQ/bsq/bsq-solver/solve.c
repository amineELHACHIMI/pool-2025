/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:29:03 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:31:16 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	**alloc_dp(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = malloc(sizeof(int *) * rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dp[i] = malloc(sizeof(int) * cols);
		if (!dp[i])
		{
			while (--i >= 0)
				free(dp[i]);
			free(dp);
			return (NULL);
		}
		i++;
	}
	return (dp);
}

static void	fill_dp(t_map *map, int **dp, t_square *best)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + min3(dp[i - 1][j],
						dp[i][j - 1], dp[i - 1][j - 1]);
			update_best(dp, best, i, j);
			j++;
		}
		i++;
	}
}

void	solve_bsq(t_map *map)
{
	int			**dp;
	t_square	best;
	int			i;

	dp = alloc_dp(map->rows, map->cols);
	if (!dp)
		return ;
	best.size = 0;
	best.row = 0;
	best.col = 0;
	fill_dp(map, dp, &best);
	fill_square(map, best);
	i = 0;
	while (i < map->rows)
		free(dp[i++]);
	free(dp);
}
