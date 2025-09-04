/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:32:34 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 15:33:22 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "utils.h"
# include <stdlib.h>

typedef struct s_entry
{
	char	*key;
	char	*val;
}			t_entry;

typedef struct s_dict
{
	t_entry	*arr;
	size_t	size;
	size_t	cap;
}			t_dict;

int			load_dict(const char *path, t_dict *d);
const char	*dict_get(t_dict *d, const char *key);
void		free_dict(t_dict *d);
int			is_numeric_str(const char *s);

#endif
