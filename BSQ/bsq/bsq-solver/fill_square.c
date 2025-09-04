/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:05 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:28:07 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_square(t_map *map, t_square best)
{
	int	i;
	int	j;

	i = best.row - best.size + 1;
	while (i <= best.row)
	{
		j = best.col - best.size + 1;
		while (j <= best.col)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}
