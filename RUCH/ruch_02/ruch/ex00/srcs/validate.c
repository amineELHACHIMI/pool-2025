/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:36:40 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 15:40:13 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_number(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*strip_leading_zeros(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == '0')
		i++;
	if (!s[i])
		return (ft_strdup("0"));
	return (ft_strdup(s + i));
}

char	*validate_inp(const char *num_str, t_dict *d, const char *dict_path)
{
	if (!validate_number(num_str))
	{
		putendl("Error");
		return (0);
	}
	normalized = strip_leading_zeros(num_str);
	if (!normalized)
	{
		putendl("Dict Error");
		return (0);
	}
	d.size = 0;
	d.cap = 0;
	d.arr = NULL;
	if (!load_dict(dict_path, d))
	{
		free(normalized);
		putendl("Dict Error");
		return (0);
	}
	return (normalized);
}
