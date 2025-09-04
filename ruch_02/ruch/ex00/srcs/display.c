/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:49:22 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 17:26:10 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	putstr(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	putendl(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

static const char	*safe_get(t_out *o, int n)
{
	const char	*v;
	const char	*key;

	int_to_str(key, n);
	v = dict_get(o->dict, key);
	if (!v)
	{
		o->error = 1;
		return (NULL);
	}
	if (o->started)
		write(1, " ", 1);
	write(1, v, ft_strlen(v));
	o->started = 1;
	return (v);
}

static int	print_0_999(t_out *o, int n)
{
	if (n >= 100)
	{
		if (!safe_get(o, n / 100) || !safe_get(o, 100))
			return (0);
		n = n % 100;
	}
	if (n >= 20)
	{
		if (!safe_get(o, n))
			return (0);
		if (n % 10)
		{
			if (!safe_get(o, n % 10))
				return (0);
		}
	}
	else if (n > 0)
	{
		if (!safe_get(o, n))
			return (0);
	}
	return (1);
}

void	print_num(t_out *out, t_dict *dict, size_t groups, char **g)
{
	int	idx;
	int	val;
	int	k;

	out->started = 0;
	out->error = 0;
	out->dict = dict;
	idx = 0;
	while (idx < groups)
	{
		val = int_from_digits(g[idx], ft_strlen(g[idx]));
		if (val != 0)
		{
			if (!print_0_999(out, val))
				out->error = 1;
			if (groups - 1 - idx > 0)
			{
				k = make_pow10_key((groups - 1 - idx) * 3);
				if (!k || !safe_get(out, k))
					out->error = 1;
			}
		}
		free(g[idx++]);
	}
}
