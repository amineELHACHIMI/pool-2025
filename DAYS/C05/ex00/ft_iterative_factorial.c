/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:47:24 by amelhach          #+#    #+#             */
/*   Updated: 2025/08/25 22:17:44 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	res = nb - 1;
	while (res != 0)
	{
		nb = nb * res;
		res--;
	}
	return (nb);
}
