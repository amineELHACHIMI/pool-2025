/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:27:16 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:27:31 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	print_error(void)
{
	write(2, "map error\n", 10);
}

static int	process_stdin(void)
{
	t_map	*map;

	map = parse_map(NULL);
	if (!map)
	{
		print_error();
		return (1);
	}
	solve_bsq(map);
	print_map(map);
	free_map(map);
	return (0);
}

static void	process_files(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	while (i < argc)
	{
		map = parse_map(argv[i]);
		if (!map)
			print_error();
		else
		{
			solve_bsq(map);
			print_map(map);
			free_map(map);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (process_stdin());
	process_files(argc, argv);
	return (0);
}
