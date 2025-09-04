/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:59:40 by amelhach          #+#    #+#             */
/*   Updated: 2025/08/20 11:20:21 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l1;
	unsigned int	l2;

	i = 0;
	l1 = 0;
	l2 = 0;
	while (l1 < size && dest[l1] != '\0')
		l1++;
	while (src[l2] != '\0')
		l2++;
	if (size <= l1)
		return (l2 + size);
	while (src[i] != '\0' && (l1 + i + 1) < size)
	{
		dest[l1 + i] = src[i];
		i++;
	}
	if (l1 + i < size)
		dest[l1 + i] = '\0';
	return (l1 + l2);
}
