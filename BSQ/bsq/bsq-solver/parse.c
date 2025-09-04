/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:41 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:28:44 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	parse_header(char *file, char **body, t_map **map)
{
	char	*line_end;

	line_end = file;
	while (*line_end && *line_end != '\n')
		line_end++;
	if (!*line_end)
		return (0);
	*line_end = '\0';
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (0);
	if (!parse_first_line(file, *map))
	{
		free(*map);
		return (0);
	}
	*body = line_end + 1;
	return (1);
}

static int	validate_body_symbols(t_map *map, char *body, int rows, int cols)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			c = body[i * (cols + 1) + j];
			if (c != map->empty && c != map->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	parse_body(t_map *map, char *body)
{
	int	rows;
	int	cols;

	if (!count_rows_cols(body, &rows, &cols))
		return (0);
	if (rows != map->rows)
		return (0);
	map->cols = cols;
	map->grid = fill_grid(body, rows, cols);
	if (!map->grid)
		return (0);
	if (!validate_body_symbols(map, body, rows, cols))
		return (0);
	return (1);
}

t_map	*parse_map(char *filename)
{
	char	*file;
	char	*body;
	t_map	*map;

	file = read_file(filename);
	if (!file || !*file)
	{
		free(file);
		return (NULL);
	}
	if (!parse_header(file, &body, &map))
	{
		free(file);
		return (NULL);
	}
	if (!parse_body(map, body))
	{
		free(map);
		free(file);
		return (NULL);
	}
	free(file);
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}
