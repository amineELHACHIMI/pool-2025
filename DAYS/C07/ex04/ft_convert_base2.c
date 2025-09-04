/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:13:12 by amelhach          #+#    #+#             */
/*   Updated: 2025/09/04 23:13:15 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_invalid(char *base);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	diff;

	diff = 0;
	while (n && (*s1 || *s2))
	{
		diff = *s1 - *s2;
		if (diff != 0)
			break ;
		s1++;
		s2++;
		n--;
	}
	return (diff);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	len;

	if (!to_find[0])
		return (str);
	len = 1;
	while (*(str + len - 1))
	{
		if (*str == to_find[0])
		{
			if (!(ft_strncmp(to_find, str, len)))
			{
				return (str);
			}
		}
		str++;
	}
	return (NULL);
}

void	ft_non_base(int *sign, char **str)
{
	*sign = 1;
	while (**str == '-' || **str == '+' || **str == ' ' || (**str >= '\t'
			&& **str <= '\r'))
	{
		if ('-' == **str)
			*sign *= -1;
		(*str)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	pw;
	int	res;
	int	base_n;

	if (str == NULL || base == NULL || !str[0])
		return (0);
	base_n = 0;
	while (base[base_n])
		base_n++;
	ft_non_base(&sign, &str);
	res = 0;
	pw = 1;
	while (ft_strstr(base, str) != NULL && *str)
		str++;
	str--;
	while (*str && ft_strstr(base, str) != NULL)
	{
		res += (ft_strstr(base, str--) - base) * pw;
		pw *= base_n;
	}
	return (res * sign);
}
