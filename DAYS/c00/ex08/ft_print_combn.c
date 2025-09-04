/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:22:13 by amelhach          #+#    #+#             */
/*   Updated: 2025/08/14 16:06:52 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	tab[9];
	int		i;

	i = 0;
	while (i < n)
	{
		tab[i] = i + '0';
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < n)
			write(1, &tab[i++], 1);
		if (tab[0] == '0' + (10 - n))
			break ;
		write(1, ", ", 2);
		i = n - 1;
		while (i >= 0 && tab[i] == '9' - (n - 1 - i))
			i--;
		tab[i]++;
		while (++i < n)
			tab[i] = tab[i - 1] + 1;
	}
}
int main(){
ft_print_combn(8);
return 0;
}
