/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:13:21 by amelhach          #+#    #+#             */
/*   Updated: 2025/09/04 23:13:24 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);

void	ft_rev_str(char *res, int init)
{
	int		i;
	int		len;
	char	temp;

	len = init;
	while (res[len])
		len++;
	i = init;
	while (i < len / 2 + init)
	{
		temp = res[i];
		res[i] = res[len + init - i - 1];
		res[len + init - i - 1] = temp;
		i++;
	}
}

int	is_invalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i] || !(base[j] > 32 && base[j] <= 126)
				|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
	}
	if (i < 1)
		return (1);
	return (0);
}

void	ft_rec_putnbr(long int n, char *base, unsigned int size, char **res)
{
	unsigned int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (*res != NULL)
		free(*res);
	*res = (char *)malloc((size + 1) * sizeof(char));
	if (n < base_len)
		(*res)[size] = 0;
	if (n >= base_len)
		ft_rec_putnbr(n / base_len, base, size + 1, res);
	(*res)[size - 1] = base[n % base_len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	n;
	char		*res;
	int			is_neg;
	int			init;

	if (is_invalid(base_from) || is_invalid(base_to))
		return (NULL);
	n = (long int)ft_atoi_base(nbr, base_from);
	init = 1;
	is_neg = 0;
	if (n < 0)
	{
		n = -n;
		is_neg = 1;
		init = 2;
	}
	res = NULL;
	ft_rec_putnbr(n, base_to, init, &res);
	if (is_neg)
		res[0] = '-';
	ft_rev_str(res, init - 1);
	return (res);
}
