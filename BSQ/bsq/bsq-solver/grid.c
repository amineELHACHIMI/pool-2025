/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:28 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:30:42 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	handle_empty_line(char **start, char **p)
{
	if (*(*p) == '\0')
		return (0);
	*start = *p + 1;
	(*p)++;
	return (1);
}

static int	handle_line(char *start, char *p, int *cols, int *rows)
{
	if (*cols == -1)
		*cols = p - start;
	else if (*cols != p - start)
		return (0);
	(*rows)++;
	return (1);
}

int	count_rows_cols(char *body, int *rows, int *cols)
{
	char	*start;
	char	*p;

	*rows = 0;
	*cols = -1;
	if (!body || *body == '\0')
		return (0);
	start = body;
	p = body;
	while (1)
	{
		if (*p == '\n' || *p == '\0')
		{
			if (p == start && !handle_empty_line(&start, &p))
				break ;
			if (p != start && !handle_line(start, p, cols, rows))
				return (0);
			if (*p == '\0')
				break ;
			start = p + 1;
		}
		p++;
	}
	return (*rows > 0 && *cols > 0);
}

static char	*alloc_line(char *start, int cols)
{
	char	*line;
	int		j;

	line = malloc(cols + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < cols)
	{
		line[j] = start[j];
		j++;
	}
	line[cols] = '\0';
	return (line);
}

char	**fill_grid(char *body, int rows, int cols)
{
	char	**grid;
	char	*start;
	int		i;

	grid = malloc(sizeof(char *) * rows);
	if (!grid)
		return (NULL);
	start = body;
	i = 0;
	while (i < rows)
	{
		grid[i] = alloc_line(start, cols);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		start += cols + 1;
		i++;
	}
	return (grid);
}
