/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:18 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:28:21 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	validate_symbols(t_map *map)
{
	if (map->empty < 32 || map->obstacle < 32 || map->full < 32)
		return (0);
	if (map->empty == map->obstacle
		|| map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

int	parse_first_line(char *line, t_map *map)
{
	int	i;

	if (!line || !*line)
		return (0);
	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	map->rows = ft_atoi(line);
	if (map->rows <= 0)
		return (0);
	if (!line[i] || !line[i + 1] || !line[i + 2] || line[i + 3])
		return (0);
	map->empty = line[i];
	map->obstacle = line[i + 1];
	map->full = line[i + 2];
	return (validate_symbols(map));
}
