/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:48:05 by amelhach          #+#    #+#             */
/*   Updated: 2025/08/31 10:03:12 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*dest;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	dest = malloc(sizeof(int) * size);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
