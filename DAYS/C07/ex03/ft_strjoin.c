/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:07:55 by amelhach          #+#    #+#             */
/*   Updated: 2025/09/03 17:09:59 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_calc_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			len++;
		if (i < size - 1)
		{
			j = 0;
			while (sep[j++])
				len++;
		}
		i++;
	}
	return (len);
}

int	ft_copy_strs(int size, char **strs, char *sep, char *res)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			res[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				res[k++] = sep[j++];
		}
	}
	res[k] = '\0';
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*res;

	if (size == 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	len = ft_calc_len(size, strs, sep);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_copy_strs(size, strs, sep, res);
	return (res);
}
