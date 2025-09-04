/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:56:06 by amelhach          #+#    #+#             */
/*   Updated: 2025/08/14 13:24:03 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int n)
{
	int	i;
	int	j;

	i = (n / 10) + '0';
	j = (n % 10) + '0';
	write(1, &i, 1);
	write(1, &j, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (b != 1)
			{
				write(1, ", ", 2);
			}
			ft_write(a);
			write(1, " ", 1);
			ft_write(b);
			b++;
		}
		a++;
	}
}
