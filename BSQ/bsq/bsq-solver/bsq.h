/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:27:40 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:27:43 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
}	t_square;

t_map	*parse_map(char *filename);
void	free_map(t_map *map);
char	*read_file(char *filename);
char	*append_buf(char *content, char *buf, int total, int bytes);
int		parse_first_line(char *line, t_map *map);
int		count_rows_cols(char *body, int *rows, int *cols);
char	**fill_grid(char *body, int rows, int cols);

void	solve_bsq(t_map *map);
int		min3(int a, int b, int c);
void	update_best(int **dp, t_square *best, int i, int j);
void	fill_square(t_map *map, t_square best);

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	print_map(t_map *map);
int		ft_atoi(char *str);

#endif
