/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:27:51 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:27:52 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	update_best(int **dp, t_square *best, int i, int j)
{
	if (dp[i][j] > best->size)
	{
		best->size = dp[i][j];
		best->row = i;
		best->col = j;
	}
}
