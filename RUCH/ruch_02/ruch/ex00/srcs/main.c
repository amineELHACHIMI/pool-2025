/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:02:09 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 15:43:20 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "dict.h"
#include "utils.h"
#include "validate.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	const char	*dict_path;
	const char	*num_str;
	char		*normalized;
	t_dict		d;

	dict_path = "numbers.dict";
	if (argc == 2)
		num_str = argv[1];
	else if (argc == 3)
	{
		dict_path = argv[1];
		num_str = argv[2];
	}
	else
	{
		putendl("Error");
		return (1);
	}
	normalized = validate_inp(num_str, &d, dict_path);
	if (!normalized)
		return (1);
	convert_number(&d, normalized);
	free(normalized);
	free_dict(&d);
	return (0);
}
